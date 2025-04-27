#! /bin/bash

# gets the root path to this repo and stores it in SCRIPT_DIR
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

IP_PORT=50000
GUI_PORT=5000
DEPLOYMENT=Commander


if [ "$1" == "C" ]; then
    echo "Commander Node"
elif [ "$1" == "0" ]; then
    echo "Node_0"
    IP_PORT=50100
    GUI_PORT=5100
    DEPLOYMENT=Node_0
elif [ "$1" == "1" ]; then
    echo "Node_1"
    IP_PORT=50110
    GUI_PORT=5110
    DEPLOYMENT=Node_1
elif [ "$1" == "2" ]; then
    echo "Node_2"
    IP_PORT=50120
    GUI_PORT=5120
    DEPLOYMENT=Node_2
else
    echo "Usage: ./demo.sh [C|0|1|2]"
    exit 1
fi

SOURCE_DIR=$SCRIPT_DIR/fprime-venv/bin/activate

source $SOURCE_DIR
fprime-gds --ip-port $IP_PORT --gui-port $GUI_PORT --deployment build-artifacts/Linux/Deployments_$DEPLOYMENT

