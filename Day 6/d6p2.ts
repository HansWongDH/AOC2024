import * as fs from 'fs';

type Direction = '^' | '>' | 'v' | '<';

const directionDeltas: { [key in Direction]: { dx: number, dy: number } } = {
    '^': { dx: 0, dy: -1 }, 
    '>': { dx: 1, dy: 0 },
    'v': { dx: 0, dy: 1 },
    '<': { dx: -1, dy: 0 },
};

function parseAndMove(map: string): number {
    const grid = map.split('\n').map(row => row.split(''));
    const rows = grid.length;
    const cols = grid[0].length;
    let count = 0;

    let x = -1, y = -1;
    let direction: Direction | null = null;

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === '^') {
                direction = grid[i][j] as Direction;
                x = j;
                y = i;
                break;
            }
        }
        if (direction) break;
    }
    for (let bRow = 0; bRow < rows; bRow++) {
        for (let bCol = 0; bCol < cols; bCol++) {
            if(grid[bRow][bCol] === '.') {
                const newGrid = duplicateGrid(grid);
                newGrid[bRow][bCol] = '#';
                count += move(direction, rows, cols, x, y, newGrid);
            }

        }
    }
    return count;
}

function duplicateGrid(grid: string[][]): string[][] {
    return grid.map(row => [...row]);
}

function move(direction: Direction | null, rows: number, cols: number, x: number, y: number, grid: string[][]): number {
    if (!direction) {
        return 0;
    }

    const visitedObstacles = new Set<string>(); 
    let count = 0;

    while (true) {
        const delta = directionDeltas[direction];
        const newX = x + delta.dx;
        const newY = y + delta.dy;

        if (newX < 0 || newY < 0 || newX >= cols || newY >= rows) {
            break; 
        }
        if (grid[newY][newX] === '#') {
            const obstacleKey = `${x},${y},${direction}`;
            if (visitedObstacles.has(obstacleKey)) {
                return 1; 
            }
            visitedObstacles.add(obstacleKey);
            direction = getNextDirection(direction);
            continue;
        }

        x = newX;
        y = newY;
    }

    return 0;
}

function getNextDirection(currentDirection: Direction): Direction {
    const directions: Direction[] = ['^', '>', 'v', '<'];
    const currentIndex = directions.indexOf(currentDirection);
    return directions[(currentIndex + 1) % 4];
}


function readMapFromFile(filePath: string): string {
    try {
        const data = fs.readFileSync(filePath, 'utf8');
        return data;
    } catch (err) {
        console.error('Error reading the file:', err);
        return '';
    }
}

const filePath = 'day6.txt';
const map = readMapFromFile(filePath);
const result = parseAndMove(map);
console.log(result);
