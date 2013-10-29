# Morse

An estoric programming language consisting of only `.` and `_`.

## Example

The following program takes the input of two numbers from the user and adds them. It asks for the input again in case the result is zero.

```
____
____
_...
_....
__._
_._.. _
```

## Build

Download the source code and build it by running:

    make

## Usage

You can run your programs by:

    ./morse [filename]

## Syntax

The execution environment maintains only 2 stacks, one for integers and other for characters.

### Stack Manipulation

Operations on the integer stack:
* `.` - Push an integer to the stack [parameter: positive integer].
* `_` - Duplicate the top most integer in the stack.
* `_.` - Swap two topmost integers in the stack.
* `__` - Pop topmost integer from the stack.

Operations on the character stack:
* `_..` - Push a character to the stack [parameter: character].
* `_._` - Duplicate the top most character in the stack.
* `__.` - Swap two topmost characters in the stack.
* `___` - Pop topmost character from the stack.

### Arithmetic Operations
* `_...` - Add top most integers and replace them with the result.
* `_.._` - Subtract top most integers and replace them with the result.
* `_._.` - Multiply top most integers and replace them with the result.
* `_.__` - Divide top most integers and replace them with the result.
* `__..` - Take modulus of top most integers and replace them with the result.

### Input/Output
* `__._` - Print topmost integer on the stack.
* `___.` - Print topmost character on the stack.
* `____` - Take an input of an integer from the user.
* `_....` - Take an input of a character from the user.

### Flow Control
* `_..._` - Jump to a line number. _[parameter: line number]_
* `_.._.` - Jump to a line number if topmost integer is positive. _[parameter: line number]_
* `_..__` - Jump to a line number if topmost integer is negative. _[parameter: line number]_
* `_._..` - Jump to a line number if topmost integer is zero. _[parameter: line number]_

### Representing literals

Numbers can be represented in their binary form, with the 0s being `.` and 1s being `_`. Characters can be represented as the corresponding binary format of their ASCII code.

**Note:** You can only represent positive integers right now.

For example:
* 2 is `_.`
* 20 is `_._..`
* A is `_....._` (binary representation of 65)

## License

MIT

## Contact

This was made out of sheer joblessness by Sankha. Follow him [@sankha93](https://twitter.com/sankha93) on Twitter.
