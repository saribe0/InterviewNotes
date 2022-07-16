# Python 3

## General
- High level
- Interpretted 
- Tons of modules
- Supports objecs, threading, exception handling, memory mangagement
- Dynamically typed

## Dynamic Typing

Python is strongly typed. i.e. "1"+2 will causes an error.

Type checking can be done:
- Statically (before execution)
- Dynamically (during execution)

Since Python is interpretted, type checking is done dynamically.

## Interpretted

Python is executed line-by-line, directly from source code. No compilation needed.

## Scope

- **local** scope is the current function
- **global** scope is the entire code since their inception
- **module-level** accessible within the entire module
- **outermost** all built-in names in the program (this is the last place searched)

Changing a `global` variable from within a function's scope (not an object but a value) requires the keyword `global`.

[Example](#https://www.programiz.com/python-programming/global-keyword)
```python
def foo():
    x = 20

    def bar():
        global x
        x = 25
    
    print("Before calling bar: ", x)
    print("Calling bar now")
    bar()
    print("After calling bar: ", x)

foo()
print("x in main: ", x)
-----------------------------------
Before calling bar: 20
Calling bar now
After calling bar: 20
x in main: 25
```

When using nested functions, changing a variable in the parent function's scope requires some indication that we don't want to write to a new local variable. For this, the keyword is `nonlocal`.

[Example](#https://www.programiz.com/python-programming/global-local-nonlocal-variables)
```python
def outer():
    x = "local"

    def inner():
        nonlocal x
        x = "nonlocal"
        print("inner:", x)

    inner()
    print("outer:", x)

outer()
-----------------------------------
inner: nonlocal
outer: nonlocal
```

## Lists vs. Tuples vs. Arrays
- List has square brackets `[]`
- Tuple has parenthesis `()`

- Lists are mutable
- Typles are immutable

Arrays can only contain elements of the same type but consume far less memory than lists. They need to be imported using `import array`. They are a thin wrapper around `C` arrays.

## Built-in Types

- None Type (`None`)
- Numeric types
    - Integers (`int`)
    - Floating point (`float`)
    - Complex numbers (`complex`)
    - Booleans (`bool`) - subtype of integers
    - Fractions (`fraction`) (standard library)
    - Decimals (`decimal`) (standard library)
- Sequence Types - these have `in` and `not in` operators defined
    - Lists (`list`) - mutable
    - Tuple (`tuple`) - immutable
    - Range (`range`) - immutable and generated during execution
    - String (`str`) - immutable unicode code points for text (standard library)
    - Byte arrays (`bytearray bytes`) (standard library)
    - Memory view (`memoryview`) (standard library)
- Mapping Types
    - Dictionary (`dict`) - comma-separated list of key, value pairs
- Set Types
    - Set (`set`) - mutable unordered collection of distinct hashable objects (can not be used as a dictionary key)
    - Frozen set (`frozenset`) - immutable collection of distinct hashable objects (hashable so can be used as a dictionary key!)
- Modules - supports attribute access through a special `__dict__` attribute (symbol table for name lookup)
- Callables - functions, instance methods, generators

## Modules and Packages

Modules are essentially `.py` files that contian sets of functions, classes, variables, etc. They can be imported via. the `import` statement. Modules help avoid global variable name clashing.

Packages allow for hierarchal organization. Packages help avoid module name clashes.

`PYTHONPATH` variable is used to search for modules and packages.

## Global, Protected, Private Attributes
- Global variables are public and in the global scope. Within a function, the `global` keyword is needed.
- Protected attributes are defined with a single underscore i.e. `_protectedVar`. This is only convention though and the variable can still be accessed externally.
- Private attributes are defined with two underscores i.e. `__privateVar`. This is only convention though and the variable can still be accessed externally.

## Memory Management

**Python Memory Manager** handles memory allocation in a *private heap space*. This space is inaccessible by programmers though has some APIs to interact with it.

Python has built in garbage collection to recycle unused memory.

## Decorators

Essentially functions that add functionality to an existing function without changing the function. Called 'bottom-up'.

[Example](#https://www.interviewbit.com/python-interview-questions/)
```python
# decorator function to convert to lowercase
def lowercase_decorator(function):
   def wrapper():
       func = function()
       string_lowercase = func.lower()
       return string_lowercase
   return wrapper
# decorator function to split words
def splitter_decorator(function):
   def wrapper():
       func = function()
       string_split = func.split()
       return string_split
   return wrapper
@splitter_decorator # this is executed next
@lowercase_decorator # this is executed first
def hello():
   return 'Hello World'
hello()   # output => [ 'hello' , 'world' ]
```

## List Comprehension

[Examples](#https://www.interviewbit.com/python-interview-questions/)
- Per element in list
    ```python
    my_list = [2, 3, 5, 7, 11]
    squared_list = [x**2 for x in my_list]    # list comprehension
    # output => [4 , 9 , 25 , 49 , 121]
    squared_dict = {x:x**2 for x in my_list}    # dict comprehension
    # output => {11: 121, 2: 4 , 3: 9 , 5: 25 , 7: 49}
    ```
- Filtering of elements
    ```python
    my_list = [2, 3, 5, 7, 11]
    squared_list = [x**2 for x in my_list if x%2 != 0]    # list comprehension
    # output => [9 , 25 , 49 , 121]
    squared_dict = {x:x**2 for x in my_list if x%2 != 0}    # dict comprehension
    # output => {11: 121, 3: 9 , 5: 25 , 7: 49}
    ```
- Combining multiple lists
    ```python
    a = [1, 2, 3]
    b = [7, 8, 9]
    [(x + y) for (x,y) in zip(a,b)]  # parallel iterators
    # output => [8, 10, 12]
    [(x,y) for x in a for y in b]    # nested iterators
    # output => [(1, 7), (1, 8), (1, 9), (2, 7), (2, 8), (2, 9), (3, 7), (3, 8), (3, 9)] 
    ```
- Flattening a multi-dimensional list
    ```python
    my_list = [[10,20,30],[40,50,60],[70,80,90]]
    flattened = [x for temp in my_list for x in temp]
    # output => [10, 20, 30, 40, 50, 60, 70, 80, 90]
    ```

## Lambda Functions
Unamed functions that can accept any number of arguments but only have a single expression.

## Copying Objects
`=` operator *does not copy objects*. Instead it binds the name to the existing object (for objects!). Copies need to be made with the `copy` module.

- Shallow Copy: Only the top level object is copied. Any subobject references will remain unchanged.
- Deep Copy: All nested objects are copied.

## Pickling

Python's in-house serialization module to dump python objects to files and load them back up. 

`pickle.dump()`
`pickle.load()`

## Generators
- Functions that return iterable collections of items, one at a time
- `yield` keyword rather than `return` keyword
- Can be used to iterate over items one at a time without pre-computing values. This enables potentially unlimitted ranges

## Iterators
- Objects that keep track of state
- `__iter__()` method itializes the iterator
- `__next__()` method to return the next item
- Must raise `StopIteration` exception at the end of the iteration

## `with` Keyword

The `with` keyword is especially useful for handling the opening and closing of resources. It requries the object has an `__enter__()` and `__exit__()` function that do setup and cleanup.

## Python Classes
- Python classes can inherrit from multiple parents
- `super()` or a parent class's name can be used to specify a parent class

The `issubclass()` and `isinstance()` methods can be used to determine if a class is a subclass or instance.

## General Notes
- `self` points to the current instance
- Python arguments are passed by reference
