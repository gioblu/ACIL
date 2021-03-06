
## BIPLAN™ CR.1
BIPLAN (Byte-coded Interpreted Programming Language) is an experimental programming language based on a recursive descent parser that uses only static memory allocation and operates a completely software-defined virtual machine that does not require a garbage collector. It's human-readable language called BIPLAN is compiled in an 7-bit ASCII virtual-machine language called BIP.

| Programming language | Minimum requirements |
| -------------------- | -------------------- |
| TinyBasicPlus        |  11KB ROM,  1KB RAM  |
| BIPLAN               |  12KB ROM,  1KB RAM  |
| Wasm3                |  64kB ROM, 10kB RAM  |
| MycroPython          | 256KB ROM, 16KB RAM  |
| Lua                  | 256KB ROM, 64kB RAM  |

BIPLAN has a modern syntax inspired by Python and it is expressly designed to operate efficiently on microcontrollers with limited resources although its implementation is designed to be easily extensible. Today the complexity of tools required for a programming language to work is often overwhelming, BIPLAN's architecture and its machine-language are designed to offer a very simple set of tools that can operate in a constrained environment with no need of external dependencies.

### Code example

Fibonacci sequence computation in 236 bytes of BIPLAN code:
```php
print fibonacci(40)
stop
function fibonacci($n)
  $a    = 0
  $b    = 1
  $next = 0
  $r    = 0
  while $r < $n
    $r = $r + 1
    $a = $b
    $b = $next
    $next = $a + $b
    if $next < 0 return end
  next
return $next
```
Compiled in 64 bytes of BIP virtual-machine language by the [`BCC`](/src/BCC.h) class:
```
p~#(40)xf#($$)$%0$&1$#0$'0w$'<$$$'$'+1$%$&$&$#$#$%+$&?$#<0rFnr$#
```
Interpreted at run time by the [`BIPLAN_Interpreter`](/src/BIPLAN.h) class:
```
102334155
```
On my linux computer the [biplan-interpreter](examples/LINUX/biplan-interpreter/) needs 124 microseconds to run the algorithm. Python needs around 170 milliseconds to run the same algorithm. BIPLAN looks to be around 1370 times quicker than python.

### Documentation
- [Configuration](/documentation/configuration.md)
- [Comments](/documentation/comments.md) [`#`](/documentation/comments.md)
- [Conditions](/documentation/conditions.md) [`if`](/documentation/conditions.md) [`else`](/documentation/conditions.md) [`end`](/documentation/conditions.md)
- [Constants](/documentation/constants.md) [`true`](/documentation/constants.md) [`false`](/documentation/constants.md) [`HIGH`](/documentation/constants.md) [`LOW`](/documentation/constants.md) [`INPUT`](/documentation/constants.md) [`OUTPUT`](/documentation/constants.md)
- [Cycles](/documentation/cycles.md) [`for`](/documentation/cycles.md#for) [`while`](/documentation/cycles.md#while) [`next`](/documentation/cycles.md#next) [`break`](/documentation/cycles.md#break) [`continue`](/documentation/cycles.md#continue)
- [Functions](/documentation/functions.md) [`function`](/documentation/functions.md) [`return`](/documentation/functions.md)
- [Numeric variables](/documentation/numeric-variables.md) [`$`](/documentation/numeric-variables.md) [`$[]`](/documentation/numeric-variables.md)
- [Operators](/documentation/operators.md) [`+`](/documentation/operators.md) [`-`](/documentation/operators.md) [`*`](/documentation/operators.md) [`/`](/documentation/operators.md) [`%`](/documentation/operators.md) [`==`](/documentation/operators.md) [`!=`](/documentation/operators.md) [`>`](/documentation/operators.md) [`>=`](/documentation/operators.md) [`<`](/documentation/operators.md) [`<=`](/documentation/operators.md) [`&&`](/documentation/operators.md) [`||`](/documentation/operators.md) [`&`](/documentation/operators.md) [`|`](/documentation/operators.md) [`^`](/documentation/operators.md) [`>>`](/documentation/operators.md) [`<<`](/documentation/operators.md) [`++`](/documentation/operators.md) [`--`](/documentation/operators.md) [`~`](/documentation/operators.md) [`not`](/documentation/operators.md)
- [Strings](/documentation/strings.md) [`:`](/documentation/strings.md) [`:[]`](/documentation/strings.md)
- [System functions](/documentation/system-functions.md) [`stop`](/documentation/system-functions.md#stop) [`restart`](/documentation/system-functions.md#restart) [`char`](/documentation/system-functions.md#print) [`sizeof`](/documentation/system-functions.md#sizeof) [`print`](/documentation/system-functions.md#print) [`delay`](/documentation/system-functions.md#delay) [`random`](/documentation/system-functions.md#random) [`millis`](/documentation/system-functions.md#millis) [`sqrt`](/documentation/system-functions.md#sqrt) [`analogRead`](/documentation/system-functions.md#analogRead) [`digitalRead`](/documentation/system-functions.md#digitalRead) [`digitalWrite`](/documentation/system-functions.md#digitalWrite) [`pinMode`](/documentation/system-functions.md#pinMode) [`serialRead`](/documentation/system-functions.md#serialRead) [`serialWrite`](/documentation/system-functions.md#serialWrite) [`input`](/documentation/system-functions.md#input) [`index`](/documentation/system-functions.md#index) [`jump`](/documentation/system-functions.md#jump)
- [Unary operators](/documentation/unary-operators.md) [`++`](/documentation/unary-operators.md) [`--`](/documentation/unary-operators.md)

### License
This work is dual-licensed under [Apache 2.0](LICENSE.Apache-2.0) and [LGPL 3.0 (or any later version)](LICENSE.LGPL-3.0-or-later).
You can choose between one of them if you use this work.

`SPDX-License-Identifier: Apache-2.0 OR LGPL-3.0-or-later`

All the software included in this project is experimental and it is distributed "AS IS" without any warranty, use it at your own risk. BIPLAN™ and its brand are registered trademarks, property of Giovanni Blu Mitolo gioscarab@gmail.com

### Safety warning
This software is experimental and may not behave as expected. Consider that using a virtual machine of this sort, specially if enabling remote program update, is dangerous. When enabling remote programming of a BIPLAN virtual machine, it must be considered potentially compromised, manipulated or remotely actuated against your will. It should be considered a good practice not to connect to the internet systems that may create a damage (fire, flood, data-leak) if hacked.
