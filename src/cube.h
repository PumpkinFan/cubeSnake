#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include "raylib.h"
#include "raymath.h"

const float cubeSize = 1.0;

struct Cube {
    Vector3 position;

    void draw();
};

void Cube::draw() {
    // DrawCube(position, cubeSize, cubeSize, cubeSize, RED);
    DrawCubeWires(position, cubeSize, cubeSize, cubeSize, BLACK);
}

// Create a 3D grid of cubes
std::vector<Cube> createCubes(int gameWidth, int gameHeight, int gameDepth) {
    // gameWidth, gameHeight, and gameDepth are the number of cubes in each direction
    std::vector<Cube> cubes;
    Vector3 gamePosition = { 0.0, 0.0, 0.0 };
    for (int i = 0; i < gameWidth; ++i) {
        for (int j = 0; j < gameHeight; ++j) {
            for (int k = 0; k < gameDepth; ++k) {
                Vector3 cubeOffset = { i*cubeSize, j*cubeSize, k*cubeSize };
                Vector3 cubePosition = Vector3Add(gamePosition, cubeOffset);
                Cube cube = {cubePosition};
                cubes.push_back(cube);
            }
        }
    }
    return cubes;
}


#endif // CUBE_H