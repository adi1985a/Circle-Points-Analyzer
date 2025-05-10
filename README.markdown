# Circle Points Analyzer

## Description
A C++ console application that generates random points and determines how many fall within a circle of a specified radius. Features a colorful interface, distance calculations, file output, and error handling. Created by Adrian Lesniak.

## Features
- Generate random points with x, y coordinates
- Calculate distance from origin
- Count points inside a circle of given radius
- Save points inside circle to `result.txt`
- Display program information
- Colorful console interface

## Requirements
- C++ compiler (e.g., g++)
- Header file: `colors.h` (not provided)
- Windows OS for full color functionality (via `colors.h`)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `colors.h` is in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o circle_points_analyzer
   ```

## Usage
1. Run the program:
   ```bash
   ./circle_points_analyzer
   ```
2. Choose options 1-4 from the menu:
   - 1: Generate and analyze points
   - 2: Load points from file (not implemented)
   - 3: Display program info
   - 4: Exit
3. For option 1:
   - Enter the number of points to generate
   - Enter the circle's radius
   - Results are saved to `result.txt`

## Notes
- Requires `colors.h` for console color and line-drawing utilities.
- Output file `result.txt` contains points inside the circle with their coordinates and distances.
- File loading (option 2) is a placeholder and not implemented.

## Author
Adrian Lesniak

## License
MIT License