#ifndef ACTOR_HPP
#define ACTOR_HPP


class Actor
{
    public:
        /** Default constructor */
        Actor( int x, int y );

        /** Default destructor */
        virtual ~Actor();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Actor( const Actor& other );

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Actor& operator=( const Actor& other );

        /** Access _x
         * \return The current value of _x
         */
        int get_x() const;

        /** Set _x
         * \param x New value to set
         */
        void set_x( int x );

        /** Access _y
         * \return The current value of _y
         */
        int get_y() const;

        /** Set _y
         * \param y New value to set
         */
        void set_y( int y );

    protected:

    private:
        int _x; //!< Member variable "_x"
        int _y; //!< Member variable "_y"
};

#endif // ACTOR_HPP
