/**
 * @file Machine.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
class Component;

class Machine
{
private:
    int mMachine = 1;
    int mX = 0;         ///< Machine x location
    int mY = 0;         ///< Machine y location
    int mFrame = 0;     ///< Current frame

    ///vector of components
    std::vector<std::shared_ptr<Component>> mComponents;

public:
    Machine() {}
    Machine(int machine);
    /**
     * Adds component to machine
     * @param component
     */
    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Updates machine
     * @param elapsed
     */
    void Update(double elapsed);
    /**
     * resets machine
     */
    void Reset();

    /**
    * Set the position for the root of the machine
    * @param location X,Y location in pixels
    */
    void SetLocation(wxPoint location) { mX = location.x; mY = location.y; }

    /**
     * Get the root position of the machine
     * @return location x,y in pixels as a point
     */
    wxPoint GetLocation() {return wxPoint(mX, mY);}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    void SetMachineFrame(int frame) { mFrame = frame; }

    /**
    * Set the machine number
    * @param machine An integer number. Each integer makes a different machine
    */
    void SetMachine(int machine) { mMachine = machine; }

    /**
    * Get the current machine number
    * @return Machine number
    */
    int GetMachine() { return mMachine; }

    /** Iterator that iterates over the actors in a picture */
    class ComponentIter
    {
    public:
        /**
         * Constructor
         * @param picture Picture we are iterating
         * @param pos Starting position \
         */
        ComponentIter(Machine *machine, int pos) : mMachine(machine), mPos(pos) {}

        /**
         * Test for end of the iterator
         * @param other Other object to test against
         * @return True if we this position equals not equal to the other position
         */
        bool operator!=(const ComponentIter &other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Component> operator *() const { return mMachine->mComponents[mPos]; }

        /** Increment the iterator
        * @return Reference to this iterator */
        const ComponentIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        Machine *mMachine;  ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    ComponentIter begin() { return ComponentIter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    ComponentIter end() { return ComponentIter(this, mComponents.size()); }

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
