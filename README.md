# Heart Congrats

A fun rainbow heart and congrats message :)

## Build and Run!

```sh
cd src
make
./heart
```

Run `./heart -h` to see all the options:
```
Usage: ./heart [-t # seconds] [-m "message"] [-w stripe_width]
```

Want to see a heart for a second every time you open the terminal?
```sh
cd src # or make sure you're in the src directory already
echo -e "\n# Heart!\n$PWD/heart -t 1 -m ''" >> ~/.bashrc
```
(or perhaps ~/.bash_profile).

## How??

I wanted to show a pretty little heart and animate a rainbow across it. The
terminal lets you display color pretty easily, is portable, and somewhat retro
and fun :). I always wondered what the deal with GIMP being able to export into
`.c` or `.h` files was, so I used that to draw a heart and export that data as
code. This program uses that data to draw that heart and animate a rainbow over
top for your (my) favorite grad.
