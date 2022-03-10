# PA1
 
This program should take a message from the user and encode the message into a ppm image, by manipulating each pixel value. 
The program should also be able to read a ppm file, and decode the secret message.

I used this project as a way to gain deeper experience in C. Specifically, I wanted to understand how to
manipulate binary numbers in a computer program, and learn how image files work.

PPM is one of the simplest image formats to manipulate, which is why I started with it. The process of 
creating a file that an operating system can read as an image was always a black box to me. So,
learning about PPM files helped me understand more about OS, and also brought be closer to
understanding JPEG, and other media formats.

One of the biggest challenges that I found interesting was the importance of designing your 
program for the correct oporating system. For example, encoding the same message into the same PPM file
would display a different result on Windows machines vs. Mac/Linux.
I would expect Mac and Linux to output the same image every time, since Mac OS is built on a Linux
kernal, but there was even discrepancy there.
