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
