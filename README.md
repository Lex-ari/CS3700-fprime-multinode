# CS3700-fprime-multinode F´ project

Link to Github: https://github.com/Lex-ari/CS3700-fprime-multinode

This project demonstrates interacting between multiple F´ deployments. A commander deployment issues subtasks to node deployments and retrieves their input. This aims to split long computing time on one deployment onto many other deployments, ideally in separated hardware.

### To run, make sure you check out the F´ installation page: https://fprime.jpl.nasa.gov/latest/docs/getting-started/installing-fprime/.

Use `fprime-bootstrap` to clone this project.
Source into `fprime-venv` and ensure that you have all the fprime requirements `pip install -r fprime/requirements.txt`
Run `fprime-util generate && fprime-util build -j20`

### A `demo.sh` script is created to make running each of the FSW binaries easier and so their communication ports do not clash. 
You can run them traditionally by calling  `fprime-gds --deployment (deployment) --ip-port (ip port) --gui-port (gui port)`

Usage of demo.sh: `./demo.sh (C|0|1|2)`
C = Commander Node.
0, 1, 2 = Task nodes.


F´ (F Prime) is a component-driven framework that enables rapid development and deployment of spaceflight and other embedded software applications.
**Please Visit the F´ Website:** https://fprime.jpl.nasa.gov.
