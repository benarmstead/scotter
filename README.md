# Scotter

Command line screenshot utility for wayland environments.

# Functionality

Capable of:

 - Taking screenshot of whole screen
 - Selecting area of screen
 - Taking a screenshot of the currently selected window

# Screenshots

## Main menu
<img src="https://github.com/benarmstead/scotter/blob/main/README_images/demo1.png">

## Save to file
<img src="https://github.com/benarmstead/scotter/blob/main/README_images/demo2.png">

# Running
`git clone https://github.com/benarmstead/scotter/`

`cd scotter`

`gcc -o scotter scotter.c`

`./scotter`

# Dependancies

Must be run on a wayland environment

Programs needed:

  - grim
  - slurp
  - jq
  - wl-clipboard
     
On arch linux systems: 

`sudo pacman -S grim slurp jq wl-clipboard`




