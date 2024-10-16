// @ts-check

const count = 1000000;

const from = { x: 0, y: 0 };
const to = { x: 1000, y: 1000 };

console.time("Line with Basic Algorithm");
const line = (x0, y0, x1, y1) => {
    const dx = Math.abs(x1 - x0);
    const dy = Math.abs(y1 - y0);
    const sx = x0 < x1 ? 1 : -1;
    const sy = y0 < y1 ? 1 : -1;
    let err = dx - dy;

    while (x0 !== x1 || y0 !== y1) {
        const e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
};

for (let i = 0; i < count; i++) {
    line(from.x, from.y, to.x, to.y);
}
console.timeEnd("Line with Basic Algorithm");

console.time("Line with Incremental Algorithm");
const line2 = (x0, y0, x1, y1) => {
    const dx = x1 - x0;
    const dy = y1 - y0;
    const steps = Math.max(Math.abs(dx), Math.abs(dy));
    const xIncrement = dx / steps;
    const yIncrement = dy / steps;
    let x = x0;
    let y = y0;

    for (let i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
    }
};

for (let i = 0; i < count; i++) {
    line2(from.x, from.y, to.x, to.y);
}

console.timeEnd("Line with Incremental Algorithm");

console.time("Line with Bresenham Algorithm");
const line3 = (x0, y0, x1, y1) => {
    const dx = Math.abs(x1 - x0);
    const dy = Math.abs(y1 - y0);
    const sx = x0 < x1 ? 1 : -1;
    const sy = y0 < y1 ? 1 : -1;
    let err = dx - dy;

    while (x0 !== x1 || y0 !== y1) {
        const e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
};

for (let i = 0; i < count; i++) {
    line3(from.x, from.y, to.x, to.y);
}

console.timeEnd("Line with Bresenham Algorithm");
