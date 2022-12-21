//
//  main.cpp
//  rec10
//
//  Created by Selina on 06/04/2018.
//  Copyright © 2018 Selina. All rights reserved.
//


#include <iostream>
#include <vector>
#include<string>
using namespace std;
class Instrument
{
public:
    
    virtual void makeSound()=0;
    virtual void play()=0;
private:
    
};
void Instrument::makeSound()
{
    cout<<"To make a sound...";
}

class Brass:public Instrument
{
public:
    Brass(int size):Instrument(),size(size){}
    void makeSound()
    {
        this->Instrument::makeSound();
        cout<<" blow on a mouthpiece of size "<<size<<endl;
    }
    
private:
    int size;
};
class String:public Instrument
{
public:
    String(unsigned pitch):Instrument(),pitch(pitch){}
    void makeSound()
    {
        this->Instrument::makeSound();
        cout<<" bow a string with pitch "<<pitch<<endl;
    }
    
private:
    unsigned pitch;
};
class Percussion:public Instrument
{
public:
   
    void makeSound()
    {
        this->Instrument::makeSound();
        cout<<" hit me!"<<endl;

    }
   
};
class Drum:public Percussion
{
public:
  
    void play()
    {
        cout<<"Boom";
    }
};

class Cello:public String
{
    public:
    Cello(unsigned pitch):String(pitch){}
    void play()
    {
        cout<<"Squawk";
    }
};

class Cymbal:public Percussion
{
    public:
   
    void play()
    {
        cout<<"Crash";
    }
};

class Trombone: public Brass
{
    public:
    Trombone(int size):Brass(size){}
    void play()
    {
        cout<<"Blat";
    }
};
class Trumpet: public Brass
{
    public:
    Trumpet(int size):Brass(size){}
    void play()
    {
        cout<<"Toot";
    }
};


class Violin: public String
{
    public:
    Violin(unsigned pitch):String(pitch){}
    void play()
    {
        cout<<"Screech";
    }
};


class Musician {
public:
    Musician() : instr(nullptr) {}

    void play()
    {
        if(instr!=nullptr)
        {
            instr->play();
        }
    }
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }
    
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }
    
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
private:
    Instrument* instr;
};
class MILL
{
public:
   
    void dailyTestPlay()
    {
        if(InstrumentStorage.size()==0)
        {
            cout<<"Currently we don't have any Instrument left!"<<endl;
        }
        else
        {
            for(size_t i=0; i<InstrumentStorage.size();++i)
            {
                if(InstrumentStorage[i]!=nullptr)
                {
                    InstrumentStorage[i]->makeSound();
                }
            }
        }
    }
    
    Instrument* loanOut()
    {
            for(size_t i=0; i<InstrumentStorage.size();++i)
            {
                if(InstrumentStorage[i]!=nullptr)
                {
                    Instrument* result= InstrumentStorage[i];
                    InstrumentStorage[i]=nullptr;
                    return result;
                }
            }
            return nullptr;
        
    }
    
    void receiveInstr(Instrument& ins)
    {
    

        if(InstrumentStorage.size()!=0)
        {
            for(size_t i=0; i<InstrumentStorage.size();++i)
            {
                if(InstrumentStorage[i]==nullptr)
                {
                    InstrumentStorage[i]=&ins;
                    return;
                }
            }
        }
    
        InstrumentStorage.push_back(&ins);
    }
private:
    vector<Instrument*> InstrumentStorage;
};

class Orch
{
public:
    Orch(){}
    void addPlayer(Musician& mu)
    {
        players.push_back(&mu);
    }
    void play()
    {
        for(size_t i=0;i<players.size();++i)
        {
            players[i]->play();
        }
        cout<<endl;
    }
private:
    vector<Musician*> players;
    
};

int main() {
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);
    
    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
} // main

