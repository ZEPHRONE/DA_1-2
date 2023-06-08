#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the color for the sun
    setcolor(YELLOW);

    // Draw the sun
    circle(320, 240, 40);
    floodfill(320, 240, YELLOW);

    // Set colors for each planet
    int planetColors[] = {WHITE, GREEN, BLUE, RED, MAGENTA, BROWN, CYAN, LIGHTRED};

    // Set the radii and speeds for each planet
    int radii[] = {70, 100, 150, 200, 260, 320, 380, 440};
    double speeds[] = {10.0, 9.0, 8.0, 7.0, 6.5, 6.0, 5.5, 5.0};

    // Animation loop
    while (!kbhit()) {
        cleardevice();  // Clear the screen

        // Draw the sun
        setcolor(YELLOW);
        circle(320, 240, 40);
        floodfill(320, 240, YELLOW);

        // Draw orbits and planets
        for (int i = 0; i < 8; i++) {
            // Calculate planet position
            int x = 320 + radii[i] * cos(speeds[i]);
            int y = 240 + radii[i] * sin(speeds[i]);

            // Draw orbit
            setcolor(WHITE);
            circle(320, 240, radii[i]);

            // Draw planet
            setcolor(planetColors[i]);
            circle(x, y, i + 10);
            floodfill(x, y, planetColors[i]);

            // Update planet position
            speeds[i] += (0.01 / (i+1));
        }

        // Delay to control the animation speed
        delay(5);
    }

    // Close the graphics window
    getch();
    closegraph();

    return 0;
}
