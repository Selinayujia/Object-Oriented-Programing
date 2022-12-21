//
//  main.cpp
//  rec04
//
//  Created by Selina on 16/02/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace ::std;
int main()
{
    int x;
    x = 10;
    cout << "x = " << x << endl;
    int* p;
    p = &x;
    cout << "p = " << p << endl;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    int joe( 24 );
    const int sal( 19 );
    int*  pI;
    pI = &joe;
    *pI = 2446;
    *pI = 7623;
    
    const int* pcI;
     pcI = &joe;
    //*pcI = 234;
     pcI = &sal;
   // *pcI = 7623;
    
    //int* const cpI;
    int* const cpI(&joe);
    //int* const cpI(&sal);
    //  cpI = &joe;
    *cpI = 234;
    //  cpI = &sal;
     *cpI = 7623;
    
    //const int* const cpcI;
    //const int* const cpcI(&joe);
    //const int* const cpcI(&sal);
    //  cpcI = &joe;
    // *cpcI = 234;
    //  cpcI = &sal;
    // *cpcI = 7623;
    struct Complex {
        double real;
        double img;
    };
//    Complex c = {11.23,45.67};
//    Complex* pC(&c);
//    class PlainOldClass {
//        public:
//        PlainOldClass() : x(-72) {}
//        int getX() const { return x; }
//        void setX( int val )  { x = val; }
//        private:
//        int x;
//    };
    

    class PlainOldClass {
        public:
        PlainOldClass() : x(-72) {}
        int getX() const { return x; }
        void setX( int x )  { this->x = x; } // HMMMM???
        private:
        int x;
        
        
        
    };
    
    
    class SpeakerSystem {
        public:
        void vibrateSpeakerCones( unsigned signal ) const {
            
            cout << "Playing: " << signal << "Hz sound..." << endl;
            cout << "Buzz, buzzy, buzzer, bzap!!!\n";
        }
    };
    
    class Amplifier {
        public:
        void attachSpeakers( const SpeakerSystem& spkrs )
        {
            if( attachedSpeakers )
            cout << "already have speakers attached!\n";
            else
            attachedSpeakers = &spkrs;
        }
        void detachSpeakers()
        { attachedSpeakers = nullptr; }
        
        // should there be an "error" message if not attached?
        void playMusic( ) const {
            if( attachedSpeakers )
            attachedSpeakers -> vibrateSpeakerCones( 440 );
            else
            cout << "No speakers attached\n";
        }
        private:
        const SpeakerSystem* attachedSpeakers = nullptr;
    };
    
    class Person {
        public:
        Person( const string& name ) : name(name) {}
        void movesInWith( Person& newRoomate ) {
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
        }
        string getName() const { return name; }
        // Don't need to use getName() below, just there for you to use in debugging.
        string getRoomiesName() const { return roomie->getName(); }
        private:
        Person* roomie;
        string name;
    };
    
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    // now model these two becoming roommates
    joeBob.movesInWith( billyJane );
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}

