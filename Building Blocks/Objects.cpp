class MyClass {

public:
    MyClass(int x)
        : myVar(x)
        , myVar2(x) {

    }

    int myFunc(double test) {
        
        this->myVar = test;

        return this->myVar;
    }

private:
    int myVar;
    int myVar2;
};

struct MyStruct {
    int thisVar;

    MyStruct(int myVar): thisVar(myVar) {

    }
};