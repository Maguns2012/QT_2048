#ifndef MYTILE_H
#define MYTILE_H

#define Exp_MulTiplier 2

class MyTile
{
public:
    MyTile() { value = 2; upgratedThisMove = false; }
    MyTile(const MyTile& other) { this->value = other.value; }
    MyTile(int value) { this->value = value;}
    int getValue() { return value; }
    void upgrade() { value *= Exp_MulTiplier; }
    void setUpgratedThisMove(bool updated) { this-> upgratedThisMove = updated; }
    bool getUpgratedThisMove() const { return this->upgratedThisMove; }
private:
    int value;
    bool upgratedThisMove;
};

#endif // MYTILE_H
