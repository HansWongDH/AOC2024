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
    if (!direction) {
        return 0;
    }


    let xCount = 0;

    while (true) {
        const delta = directionDeltas[direction];
        const newX = x + delta.dx;
        const newY = y + delta.dy;

        if (x + delta.dx < 0 || y + delta.dy < 0 || x + delta.dx >= cols || y + delta.dy >= rows) {
            break;
        }
        if (grid[newY][newX] === '#') {
            direction = getNextDirection(direction);
            continue;
        }


        x = newX;
        y = newY;

        if (grid[y][x] != 'X') {
            xCount++; 
            grid[y][x] = 'X';
        }
  
        


    }

    return xCount;
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
