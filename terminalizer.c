/*
 * Copyright (c) 2017, Sohrab Monfared <sohrab.monfared@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

  unsigned int to_sleep = 0;
  unsigned int speed = 5; 

  if (argc < 2){
    fprintf(stderr, "usage: %s \"Your text here.\" [speed] \n", argv[0]); 
    return -1;
  }

  if (argc > 2) {
    speed = atoi(argv[2]);
  }

  if (speed > 10 || speed < 1){
    fprintf(stderr, "Speed must be a value between 1 and 10.\n");
    return -2;
  }

  while(*argv[1] != '\0'){

    to_sleep = ((*argv[1] * 90)) * speed;

    if (*argv[1] >= 'A' && *argv[1] <= 'Z'){
      to_sleep *= 4;
    }

    if (*argv[1] >= 'a' && *argv[1] <= 'z'){
      to_sleep *= 2;
    }

    if (*argv[1] < 65){
      to_sleep *= 11;
    }

    putc(*argv[1]++, stdout);
    usleep( to_sleep );
    fflush(stdout);

  }

  putc('\n', stdout);

  return 0;
}
