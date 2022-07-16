# C

## Data Hiding (Kinda)
* Pointers to undefined structs (defined elsewhere). Functions to interact with them elsewhere as well (i.e. defined in header, implemented in source).

* Static functions can only be used in the file they're declared in

## Object Oriented
- Only structs with public variables (no functions).
- No function overloading.

Can create a struct to contain data and struct-specific functions on (global) to act on them. "Inherited" classes have equal struct-specific functions. No overloading so they'd need overload-specific function names as well.

From [Stack Overflow](https://stackoverflow.com/questions/1403890/how-do-you-implement-a-class-in-c):
```C
typedef struct {
  float (*computeArea)(const ShapeClass *shape);
} ShapeClass;

float shape_computeArea(const ShapeClass *shape)
{
  return shape->computeArea(shape);
}
...
typedef struct {
  ShapeClass shape;
  float width, height;
} RectangleClass;

static float rectangle_computeArea(const ShapeClass *shape)
{
  const RectangleClass *rect = (const RectangleClass *) shape;
  return rect->width * rect->height;
}
...
void rectangle_new(RectangleClass *rect)
{
  rect->width = rect->height = 0.f;
  rect->shape.computeArea = rectangle_computeArea;
}
...
void rectangle_new_with_lengths(RectangleClass *rect, float width, float height)
{
  rectangle_new(rect);
  rect->width = width;
  rect->height = height;
}
```

## Calloc() vs Malloc()

Calloc
- Accessing the returned pointer directly returns 0
- Takes in the number of blocks AND the size of each block
- Initializes each memory block to zero

Malloc
- Accessing the returned pointer causes a segmentation fault or returns garbage
- Takes in the size of the space to allocate
- No initialization

## Pros / Cons

Pros
- Extensible 
- Fast
- Built in memory management
- Mid level language (machine + app)
- Platform independence / Portability
- Simplicity
- Structured (functions)

Cons
- No OOP
- No runtime error checking
- No namespaces (or name mangling) = variables must be unique
- No exception handling
- Not much abstraction

## General Notes
- Header files with `<...>` are only from the built-in include paths (includes `-I` option). While with `"..."` will first search the current working directory and 'quote' directories (`-quote` option).
- `volatile` prevents the compiler form optimizing an object or variable. It's value may change at any time outside the current code's scope. 
- `extern` indicates the object is externally defined by some other object or class. No header file is needed.
- Preprocessor -> Compiler -> Assembler -> Linker
- Register is used for storing a variable in a machine register. May speed up access times.
- `auto` is virtually unused and useless in `C`. It's a holdover from `B`.