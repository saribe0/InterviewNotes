# Swift

## Classes vs. structs

| struct | class |
|---|---|
| Value type | Reference type |
| No inheritance | Supports inheritance |
| Mutating functions must be marked | No need to mark mutating functions |
| `let` instances can't call mutating functions | `let` instances can call mutating functions |

## Optionals

Optionals let you set a  variable to `nil`. This holds for both reference and value types. 

*In Objective-C, this only heald for reference types (like classes)*

- `nil` == `.none`, though `nil` is the recommended convention

### Unwrapping Optionals
Forced - unsafe
```swift
let a: String = x!
```
Implicitly - unsafe in most cases
```swift
let a: String = x!
```
Optional binding - safe
```swift
if let a = x {
  print("x was successfully unwrapped and is = \(a)")
}
```
Optional chaining - safe
```swift
let a = x?.count
```
Nil coalescing - safe
```swift
let a = x ?? ""
```
Guard statement - safe
```swift
guard let a = x else {
  return
}
```
Optional pattern - safe
```swift
if case let a? = x {
  print(a)
}
```

## Generics

Similar to templates in C++. Generics let you specify a function can take multiple types that conform to a specific protocol.

```swift
func areTheyEqual<T: Equatable>(_ x: T, _ y: T) -> Bool {
  return x == y
}
```

## Closures

Closures are reference types. If you assign one to a varaible and copy it, you copy the referecne to the same closure and it's capture list.

### Capture Lists

Capture lists create copies of variables when they're declared.

```swift
var thing = "cars"

let closure = { [thing] in
  print("I love \(thing)")
}

thing = "airplanes"

closure()

> I love cars
```
vs.
```swift
var thing = "cars"

let closure = {
  print("I love \(thing)")
}

thing = "airplanes"

closure()

> I love airplanes
```

## Static vs. Class Functions

`static` makes a function *not overridable*. Using `class` lets it be overridden.

`static` == `class final` in this case.

## Extensions
- Can not be used to add stored property types, only extending behavior. No way to add extra memory to the store the value.

## Protocols
- An interface of methods, properties, etc. for a class, structure or enum to conform to.
- Typically do not provide function.
- Can be extended (must be via extension) to provide a default implementation.
    - Runtime polymorphism of types conforming to protocols IF the function with the default implementation is part of the protocol.

### Initialize by Literal

Types can conform to the protocol `ExpressibleByFloatLiteral` which enables them to be created by `=`.

```swift
extension Thermometer: ExpressibleByFloatLiteral {
  public init(floatLiteral value: FloatLiteralType) {
    self.init(temperature: value)
  }
}

var thermometer: Thermometer = 56.8
```

## Custom Operators
- `precedencegroup`'s can be used to declare the precedence of an operator relative to others (i.e. multiplication).
- `infix` = `binary` operator (two options)

```swift
precedencegroup ExponentPrecedence {
  higherThan: MultiplicationPrecedence
  associativity: right
}
infix operator ^^: ExponentPrecedence
```

Then the implementation of the operator:
```swift
func ^^(base: Int, exponent: Int) -> Int {
  let l = Double(base)
  let r = Double(exponent)
  let p = pow(l, r)
  return Int(p)
}
```

## General Notes
- `let` is the similar to `const` in C/C++
- `let` variables are determined at runtime and can be initialized with dynamic expressions - but only once!
- `var` is for variables
- Supports runtime polymorphism (for protocols with default implementations as well)
    - This has to 
- Can not deallocate instances that have strong references to them.
    - Two instances with strong references to each other causes a circualar reference and a memory leak. One should be `weak` or `unowned`.
- `indirect` keyword required for recursive enumeration cases.