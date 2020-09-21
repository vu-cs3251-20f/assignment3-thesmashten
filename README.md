# CS 3251: Intermediate Software Design

## Programming Assignment 3

This assignment focuses on strong exception safety.  As always, you have been provided with several source files to start with:

* `include/ArrayList.h`
* `include/ArrayListIter.h`
* `include/ScopedArray.h`
* `src/ScopedArray.cpp`
 
And several building and testing files:

* `tests/main.cpp`
* `tests/arrayTest.cpp`
* `tests/arrayIterTest.cpp`
* `tests/constArrayTest.cpp`
* `.github/`
* `.clang-format`
* `.gitignore`
* `.travis.sh`
* `.travis.yml`
* `CMakeLists.txt`
* `README.md`


Do not modify any of the build & test files.  Also, do not modify the header files.  The only exception to this is enabling Github actions by pulling forward the .github actions folder. 

The files _ArrayList.h_ and _ArrayListIter.h_ contain comments that specify the class's functionality. Your task is to implement all of the classes and methods declared in _ArrayList.h_ and _ArrayListIter.h_ in a **strongly-exception** safe manner. I have purposefully omitted marking methods as ```noexcept``` in the headers so that you have to evaluate the methods safety.  You should not modify the headers to add ```noexcept``` - just make the implementation itself as safe as possible.  You should use the _ScopedArray.h_ class supplied in this repository, but do compare it to your solution from the previous assignment.

The assignment is to be submitted using the link to github.com sent out via email to all class members. DO NOT email your assignment to the professor or the TAs.  Emailed assignments ARE NOT accepted.  We will grade the last commit to your repository before the deadline date and time.  Any commits after that moment will be ignored.  If nothing has been committed at that time you will receive a zero grade. 


### Undergraduate Students: 

Undergraduates are to implement the functionality described in the _include/ArrayList.h_ and _include/ArrayListIter.h_ files.  Read through the files carefully, and study the test cases defined in _tests/arrayTest.cpp_ and _tests/arrayIterTest.cpp_.  These will be your guide for what the code must do.  Then review your code to ensure it is strongly exception safe.  **Undergraduates do not need to implement the const iterator.  Do not remove or change any of the supplied files because of this requirement**.  These are all templated classes, so if we don't use a method, the compiler will not include it.  Be aware that use of STL algorithms (such as std::copy) will frequently make use of the const interator - so, only use those if you know what you are doing.

### Graduate Students: 

Graduate students are to complete the same steps as the undergraduates, described above. Additionally, graduate students are required to implement a constant iterator version of the _ArrayListIterator_ class.  Declare the class at the bottom of _include/ArrayListIter.h_ and provide the implementation at the bottom of _src/ArrayListIter.cpp_.  Also create at least six (6) good test cases for the constant ArrayListIterator.  Use the skeleton testing file _tests/constArrayTest.cpp_ for the test code.

## Reminders

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.

* Do not alter any of the project files!  Work only on those files specified above.  You must use the supplied `CMakeLists.txt` file as is.

* All students are required to abide by the CS 3251 coding standard, [available on the course web page](https://vuse-cs3251.github.io/style-guidelines/) and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with a recent version of `clang` or `gcc` and run successfully with the CI platform.
  * The CI build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `linter` or `clang-format` in the CI build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository. 
