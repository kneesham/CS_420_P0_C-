# cs_4280_P0 - Ted Nesham Fall 2020
OPEN IN MARKDOWN EDITOR OR CAT TO CONSOLE. OTHERWISE ITS HARD ON THE EYES...
### Program execution:
***
P0 // read from the keyboard until simulated EOF <br/>
P0 < somefile.fs // same as above except redirecting from somefile instead of keyboard, this tests keyboard input <br/>
P0 somefile  // read from somefile.fs<br/>

### Sources:
***
argHandler.c -> Contains the logic to handle proper/improper command line arguments <br/>
fileManageer.c -> Contains functions for creating, reading, and writing files. <br/>
tree.c -> Contains functions for printing (All different orders) as well as logic for creating the tree. <br/>
util.c -> Contains helper functions that handle: printing Sets, character comparisons, and Set Building.

### Headers:
***
argHandler.h <br/>
fileManageer.h <br/>
tree.h <br/>
node.h <br/>
util.h <br/>
 
### Output Files:
  ***
  The following files record what was outputed to the console from the most recent execution: <br/>
- out.preorder <br/>
- out.inorder <br/>
- out.postorder <br/>

### Testing:
  ***
To run the tests simply invoke the follwing command:
```  ./P0 P0_test3 // there is also P0_test2  and P0_test1 ```

### Example Execution:
  ***
# ./P0 P0_test3

``` 
PRINTING THE TREE POST-ORDER
      2: { 2 }
    1: { 123 }
      d: { duck }
    g: { george gorge }
  a: { ada adam ala asa }
  s: { susana }
j: { james jim john }

PRINTING THE TREE IN-ORDER
  a: { ada adam ala asa }
    1: { 123 }
      2: { 2 }
    g: { george gorge }
      d: { duck }
j: { james jim john }
  s: { susana }

PRINTING THE TREE PRE-ORDER
j: { james jim john }
  a: { ada adam ala asa }
    1: { 123 }
      2: { 2 }
    g: { george gorge }
      d: { duck }
  s: { susana }
```
# ls .

```
argHandler.cpp  fileManager.cpp  main.cpp  node.h       P0_test2.fs  *** P0_test3.inorder  *** P0_test3.preorder  tree.cpp  util.cpp
argHandler.h    fileManager.h    makefile  P0_test1.fs  P0_test3.fs  *** P0_test3.postorder  README.md          tree.h    util.h
```
Note that *** indicates the output files. If there is no specified file or program reads from stdin the output files will be named: out.*. <br/>

### makefile:
  ***
  -- ``` make noout``` // Will remove any output files previously created. <br/>
  -- ``` make ``` // build project <br/>
  -- ``` make clean ``` // remove .o files and executables.
  -- ``` make cobj ``` // remove any .o files.

