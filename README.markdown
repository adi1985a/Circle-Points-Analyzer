# 🎯⭕ CirclePoint Analyst Pro: Random Point Distribution 🌌
_A C++ console application for generating random 2D points and analyzing how many fall within a user-defined circle._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Project Description](#-project-description)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Running](#️-installation-and-running)
6.  [How to Use](#️-how-to-use)
7.  [Technical Details & Program Logic](#-technical-details--program-logic)
8.  [Contributing](#-contributing)
9.  [Author](#️-author)
10. [License](#-license)

## 📝 Project Description

**CirclePoint Analyst Pro** is an engaging C++ console application designed to explore the distribution of randomly generated 2D points relative to a circle centered at the origin. Users can specify the number of points to generate and the radius of the circle. The program then calculates the distance of each point from the origin and determines how many fall within the circle's boundary. Results, including the coordinates and distances of points inside the circle, are saved to `result.txt`. The application features a colorful user interface and basic error handling, making it a neat tool for visualizing simple geometric probability or Monte Carlo method concepts.

## ✨ Key Features

*   ✨ **Random Point Generation**: Creates a user-specified number of 2D points with random `x` and `y` coordinates (within a predefined range).
*   📏 **Distance Calculation**: Accurately calculates the Euclidean distance of each generated point from the origin (0,0).
*   ⭕ **Points-in-Circle Counting**: Determines and counts how many of the generated points lie within (or on the boundary of) a circle of a user-specified radius.
*   💾 **Results to File**: Saves the coordinates and calculated distances of all points that fall inside the circle to `result.txt`.
*   ℹ️ **Program Information Display**: Provides basic information about the application.
*   🌈 **Colorful Console Interface**: Enhanced user experience with colored text for menus, prompts, and output, facilitated by `colors.h` (Windows-specific for full effect).
*   ✔️ **Input Validation**: Basic checks for user inputs (e.g., number of points, radius).
*   📋 **Menu-Driven Operation**: Simple and intuitive menu for easy navigation.

## 🖼️ Screenshots

**Coming soon!**

_This section will be updated with screenshots showcasing the main menu, input prompts for point generation and radius, the summary of points inside the circle, and an example of the `result.txt` file content._

## ⚙️ System Requirements

*   **Operating System**: Windows is recommended for full color functionality, as the console color system likely relies on Windows-specific API calls abstracted in `colors.h`.
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
*   📄 **`colors.h` Header File (User-Provided)**: This project **critically requires** a header file named `colors.h`. **This file is not included in the repository and must be created by the user.** It should define color constants and utility functions for console manipulation (e.g., setting colors, drawing lines). See the "Installation and Running" section for more details.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Create `colors.h`**:
    Before compiling, you **must** create a file named `colors.h` in the project's root directory. This file should define necessary utility functions. Here's an illustrative example:
    ```cpp
    #ifndef COLORS_H
    #define COLORS_H

    #include <string>
    #ifdef _WIN32
    #include <windows.h> // For SetConsoleTextAttribute
    #include <conio.h>   // For _getch() if used
    #endif
    #include <iostream>  // For std::cout, std::cin
    #include <fstream>   // If helpers include logging or file ops

    // Example: Console Color Constants
    const int CLR_DEFAULT = 7;
    const int CLR_TITLE = 14;    // Yellow
    const int CLR_MENU = 11;     // Light Cyan
    const int CLR_PROMPT = 10;   // Light Green
    const int CLR_RESULT = 9;    // Light Blue
    const int CLR_INFO = 15;     // Bright White
    const int CLR_ERROR = 12;    // Light Red

    // Function declarations - implement these in colors.cpp or as inline
    void setColor(int colorCode);
    void drawLine(char c = '-', int length = 50); // Example utility
    // Potentially:
    // void clearScreen();
    // void waitForKeyPress(const std::string& message = "Press any key to continue...");
    // void logMessage(const std::string& message, const std::string& logFilePath = "analyzer.log");

    #endif // COLORS_H
    ```
    *Adjust these constants and function declarations to precisely match what your `main.cpp` expects. Implement these functions, likely in a `colors.cpp` file that you'll compile alongside `main.cpp`.*

4.  **Compile the Program**:
    Open a terminal (like Command Prompt or PowerShell) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp colors.cpp -o circle_points_analyzer.exe -static-libgcc -static-libstdc++
    ```
    *(This assumes you have `colors.cpp` for the implementations of functions declared in `colors.h`. If all utility logic is inline in `colors.h`, the `colors.cpp` part can be omitted).*

5.  **Run the Application**:
    After successful compilation, execute the generated program:
    ```bash
    ./circle_points_analyzer.exe
    ```
    or simply in CMD:
    ```bash
    circle_points_analyzer.exe
    ```

## ▶️ How to Use

Upon launching, **CirclePoint Analyst Pro** will display a main menu:

1.  **Generate and analyze points**:
    *   Prompts you to enter the **number of random points** to generate.
    *   Prompts you to enter the **radius of the circle** (centered at the origin).
    *   The program then generates the points, calculates how many fall within the circle, displays a summary, and saves the details of the points inside the circle to `result.txt`.
2.  **Load points from file**:
    *   *(This option is noted as **not implemented** in the description. If implemented, it would load point data from a file for analysis.)*
3.  **Display program info**:
    *   Shows basic information about the application, its purpose, and possibly the author.
4.  **Exit**:
    *   Terminates the application.

## 💡 Technical Details & Program Logic

*   **Point Generation**: Random `x` and `y` coordinates for points are generated, typically within a square bounding box (e.g., -radius to +radius, or a fixed range like -1 to 1 if normalizing for Monte Carlo Pi estimation). C++ `<random>` or `rand()` can be used.
*   **Distance Formula**: The Euclidean distance `d` of a point (x, y) from the origin (0,0) is calculated using `d = sqrt(x*x + y*y)`.
*   **Point in Circle Check**: A point is inside (or on the boundary of) the circle if its calculated distance `d` from the origin is less than or equal to the circle's radius `R` (i.e., `d <= R`).
*   **`colors.h`**: This crucial user-provided header file defines color constants and utility functions (like `setColor`, `drawLine`) for managing the console's appearance.
*   **File Output**: The `result.txt` file will typically contain a list of points that fell inside the circle, formatted to show their x-coordinate, y-coordinate, and their calculated distance from the origin.
*   **Error Handling**: Basic error handling for invalid user inputs (e.g., non-positive radius or number of points).

## 🤝 Contributing

Contributions to **CirclePoint Analyst Pro** are welcome! If you have ideas for implementing the "Load points from file" feature, adding graphical point plotting (e.g., using ASCII art or linking to a plotting library), enhancing statistical analysis, or improving the UI:

1.  Fork the repository.
2.  Create a new branch for your feature: `git checkout -b feature/your-geo-enhancement`
3.  Implement your changes and commit them: `git commit -m "Feature: Add your geo enhancement"`
4.  Push your changes to your branch: `git push origin feature/your-geo-enhancement`
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to the project's existing style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Computational Geometry Enthusiast_

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
🌍 _Visualizing randomness, one point at a time._
