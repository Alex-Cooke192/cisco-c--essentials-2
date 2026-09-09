#include <iostream>

using namespace std; 

// -----------------------------------------------

class tree {
    private:

    public:
    virtual void draw(); 

}; 

void tree::draw() {
    cout << endl; 
    cout << " /\\" << endl;
    cout << "/  \\" << endl;
    cout << endl; 
}

// ----------------------------------------------

class oak : public tree {
    private:

    public:
    void draw();
    
}; 

void oak::draw() {
    cout << endl; 
    cout << " /\\" << endl; 
    cout << "//\\\\" << endl;
    cout << endl; 
}

// -------------------------------------------------

class spruce : public tree {
    private:

    public:
    void draw(); 
}; 

void spruce::draw() {
    cout << endl; 
    cout << " /\\" << endl;
    cout << "/++\\" << endl; 
    cout << endl; 
}

// ---------------------------------------------------

class birch : public tree{
    private:

    public:
    void draw(); 
}; 

void birch::draw() {
    cout << endl; 
    cout << " /\\" << endl;
    cout << "/**\\" << endl; 
    cout << endl; 
}

int main() {
    tree* baseTree[3]; 
    oak oakTree; 
    spruce spruceTree; 
    birch birchTree; 

    baseTree[0] = &oakTree; 
    baseTree[1] = &spruceTree; 
    baseTree[2] = &birchTree; 

    for (int i=0; i<3; i++) {
        // Call the tree.draw method (it doesnt care what type of tree it is)
        baseTree[i]->draw(); 
    }
}