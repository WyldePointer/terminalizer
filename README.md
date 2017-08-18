### Compiling
`$ cc -o terminalizer -Wall -pedantic -std=c89 -D _BSD_SOURCE terminalizer.c`

### Usage
`$ ./terminalizer "Your, text here which contains some letters and symbols"`

Or if you want it to read the content of your file or output of a command:

`$ cat my_text_file_or_command_name | xargs -0 "/path/to/terminalizer"`

Optionally you can supply a 2nd argument which is speed.
 1 for the fastest and 10 is the slowest possible value.

Enjoy!
