# This is a result of Apriorit training tasks.</br>
## Task 1:
Create an application for copying files with a help of sendfile() linux function.
Function main() and function for copying MUST be placed in a different files. File with function for
copying (which use sendfile() internally) must be built to static library. During the build process file
with main() must be linked with a created static library. Copied file must be a FULL copy of the
original one (except full path/name of course). To enter original file name and name of the copy
could be used program arguments or input during the execution. For build process must be used
makefile.
## Task 2:
Create an application which opens unnamed pipe and creates new process using fork(). After that
child process writes to pipe message "Hi daddy, I'm your child!" and finishes its execution. Parent
process must read this message from a pipe, append string "Hi!" to the end. After that parent
process must save final text with two messages to file on a disk. Makefile must be used as a build
system.
