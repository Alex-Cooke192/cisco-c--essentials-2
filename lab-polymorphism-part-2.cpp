#include <iostream> 
#include <string>

using namespace std; 

struct position {
    int row; 
    char column; 
}; 

class Piece {
    protected:
    position Position; 

    public:
    Piece(position Position); 
    virtual bool checkMove(position newPosition) = 0; 
    position getPosition() {return Position;}; 
    void setPosition(position newPosition) {Position.column = newPosition.column; Position.row = newPosition.row;}; 
}; 

Piece::Piece(position Position) {
    this->Position.row = Position.row; 
    this->Position.column = Position.column; 
}

// --------------------------------------------------------------

class King : public Piece {
    private:

    public:
    using Piece::Piece; 
    bool checkMove(position newPosition); 
}; 

bool King::checkMove(position newPosition) {
    // Calculate difference between current row and new row
    int rowDiff = abs(this->Position.row - newPosition.row); 

    // Calculate difference between current column and new column
    int columnDiff = abs(this->Position.column - newPosition.column); 

    // In a diagonal move, the change in the columns must be the same as the rows
    if (rowDiff == columnDiff) {
        return true;
    } else {
        return false; 
    }
}

// ---------------------------------------------------------------

class Man : public Piece {
    private:

    public:
    using Piece::Piece; 
    bool checkMove(position newPosition); 
    position getPosition();
}; 

bool Man::checkMove(position newPosition) {
    // Number must increase by 1
    if (newPosition.row != (this->Position.row+1)) {
        return false;
    } 

    // Letter must increase OR decrease by 1
    if (abs(newPosition.column - this->Position.column) != 1) {
        return false;
    }

    // If we've got past both checks, the move is valid
    return true; 
}

// -------------------------------------------------------
// LONE METHODS
// -------------------------------------------------------

/*
bool verifyMove(piece Piece, position newPosition) {

}
*/


int main() {
    cout << "Start of program!" << endl;

    char pieceTypeIndicator; 

    cout << "Enter type of piece" << endl; 
    cout << "'k' for king" << endl;
    cout << "'m' for man" << endl; 

    cin >> pieceTypeIndicator; 

    // Set position of piece
    position Position; 

    cout << "Enter current position of piece" << endl;
    cin >> Position.column >> Position.row;

    // Take in new position to move piece to
    position NewPosition;

    cout << "Enter new position of piece" << endl;
    cin >> NewPosition.column >> NewPosition.row; 

    bool result; 
    if (pieceTypeIndicator == 'k') {
        Piece* piece = new King(Position);
        result = piece->checkMove(NewPosition); 
    } else if (pieceTypeIndicator == 'm') {
        Piece* piece = new Man(Position); 
        result = piece->checkMove(NewPosition); 
    } 

    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

}