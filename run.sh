#!/bin/bash
# Build and run Railway Reservation System

cd "$(dirname "$0")"

echo "Building project..."
make clean
make

if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

mkdir -p data
echo ""
echo "Starting program..."
echo "Use train numbers: 001, 002, 003 ..."
echo ""
./railway_system
