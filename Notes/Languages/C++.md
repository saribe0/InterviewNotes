
# C++

## New C++ Versions

https://github.com/saribe0/modern-cpp-features#special-member-functions-for-move-semantics

## vs. C

| C | C++ |
|---|---|
| Proccedure oriented | Object oriented |
| Limitted data hiding | Data hidden through encapsulation |
| No overloading | Function & operator overloading |
| No namespaces | Namespaces to avoid name collisions |
| No functions inside structs | Functions inside structs | 
| calloc(), malloc(), free() | new, delete |

## Data types
- Primitives (char, short, int, float, long, double, bool)
- Derived (array / pointer)
- Enumeration (enum)
- User defined (struct, class)

## Data Hiding
private / public / protected variables **encapsulated** in classes and structs. 

## Class vs. Struct
| Struct | Class |
|---|---|
| Members public by default | Members private by default |

## Polymorphism

**Compile Time Polymorphism**: Function overloading and operator overloading. 
**Runtime Polymorphism**: Virtual functions and function overriding in derrived classes.

- Virtual functions are redefined by derived classes. Using the keyword `virtual` causes C++ to determine the function to call at runtime. 
- Pure virtual functions create abstract classes that can not be used to create objecst. They must be derived and the function implemented for the class to be used.
- Run time polymorphism is *slower* than compile time.
- Virtual functions can be called from a constructor but (due to order of construction) the derived classes implementation won't get called - only the current classes.

When a non-virtual function is overridden in a derived class, the derived version is called when the object is of type derived class or a pointer to the derived class. If the object is passed as a base class pointer, the base class's implementation will get called.

When a virtual function is overridden in a derived class, the derived version is called regardless of the pointer type (runtime polymorphism).

### Vtable & Vptr
A **VTABLE** is a table that contains memory addresses of all virtual functions of a class in the order they're declared. Used to resolve function calls dynamically.

A **VPTR** is a hidden pointer in an object of every class with a virtual function that points to the the **VTABLE** for that class. 

Gets allocated inside the process address space.

### Name Mangling and "extern C"

When object code is created, overloaded functions are made unique through name mangling. i.e. changing the name to include information about the arguments.

Different compilers may add different bits of information.

C doesn't allow function overloading and therefor name mangling. Using `extern C` tells the compiler to not mangle names which enables linking between C++ & C functions. 

## 'Friend' classes and functions

- A friend class can access private & protected members of classes it declares as 'friends'
- A friend function can also access private & protected members but *friend functions are not member functions*.

## Reference Variables

Basically a pointer that doesn't need to be de-referenced.

```C++
int x=10;
int &ref=x;
ref=12;
cout << x << endl;

> 12
```

## Static
- Static member variables are shared by all instances of a class.
- Static member functions are called on the *class*, not an instance. They're called using the `::` operator.

## Copying

- Copy constructors create copies of a class using the current class. Default copy constructor exists via. `=`.
- Shallow copy does not copy objects, just references to them.
- Deep copy makes copies of objects and is slower.
- The default copy constructor makes a *shallow* copy.

```C++
ClassName (const ClassName &old_obj); 
```

## Malloc vs. New

| `malloc()` | `new` |
|---|---|
| C and C++ | C++ only |
| Allocates memory | Allocates memory & calls constructor |
| Does not call constructor | Calls constructor |
| Is a function | Is an operator |
| Returns void* | Returns exact data type |
| On failure, returns NULL | On failure, throws exception |
| Size calculated manually | Size calculated by compiler |

```C++
// Create an object of class A
    // using new operator
    A* a = new A;
    cout << "Object of class A was "
         << "created using new operator!"
         << endl;
 
    // Create an object of class A
    // using malloc operator
    A* b = (A*)malloc(sizeof(A));
    cout << "Object of class A was "
         << "created using malloc()!"
         << endl;
```

### Placement `new`

Placement `new` lets you create an object at a specific spot in memory. 

Some uses:
- Memory mapped I/O devices that required creating an object at a specific memory area.
- Constructing multiple instances of an object. May want to preform the 'allocation' only once. 

Can not use `delete` unless the memory location is in the heap.

## C++ ABI

C++ does not have a stable **Application Binary Interface**. It changes from time to time as C++ adds new features (think `std::string` vs. `std::c++11::string`).

Object files (mostly libraries) are compiled using a specific ABI and are compatible with other files also compiled using the same ABI. 

C++ name mangling can be done in accordance to a specific ABI. For this reason, using `extern "c"` can get around this.

The GCC C++ ABI is forward compatible. A library made with older version should work with newer version. The reverse is not true.

## Other Notes
- Deconstructor overloading is not possible. Deconstructors take no arguments.
- During construction, base classes are constructed first then built up. This is reversed for destruction.
- Void pointers don't have a data type and can point to anything. They need to be cast to actual data types.
- `this` pointer is set to the address of the object for which it's called.
- `delete this` will work if `this` is created dynamically (not recommended).
