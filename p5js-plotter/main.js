/* By adventureofe(John Gormley)

   A graphing program for plotting mathematically functions
   
   the_adventure_of_e λ */

const centre_cross_size = 3
const x_range = 700
const x_precision = 0.01
const f_pixel_size = 2

function setup()
{
    createCanvas(windowWidth, windowHeight)
    angleMode(DEGREES)
}

const init_window = () => 
{
    background(0);
    strokeCap(SQUARE);
    translate(windowWidth / 2, windowHeight / 2)
}

const red = () => {fill(255, 0, 0); stroke(255, 0, 0)}
const orange = () => {fill(255, 125, 0); stroke(255, 125, 0)}
const yellow = () => {fill(255, 255, 0); stroke(255, 255, 0)}
const lime = () => {fill(125, 255, 0); stroke(125, 255, 0)}
const green = () => {fill(0, 255, 0); stroke(0, 255, 0)}
const indigo = () =>{fill(0, 255, 125); stroke(0, 255, 125)}
const blue = () => {fill(0, 0, 255); stroke(0, 0, 255)}
const magenta = () =>{ fill(255, 0, 255); stroke(255, 0, 255)}
const cyan = () => {fill(0, 255, 255); stroke(0, 255, 255)}
const white = () => {fill(255, 255, 255); stroke(255, 255, 255)}
const black = () => {fill(0, 0, 0); stroke(0, 0, 0)}

const gridspacing = spacing => 
{
    for (let i = -x_range; i < x_range; i += spacing)
    {
        line(i, windowHeight/2, i, -windowHeight/2);
        line(windowWidth / 2, i, -windowWidth / 2, i)
    }
}

const centre_cross = () => 
{
    strokeWeight(3)
    line(0, windowHeight / 2, 0, -windowHeight / 2)
    line(windowWidth / 2, 0, -windowWidth / 2, 0)
}

const f = func => 
{
    strokeWeight(0)
    for(let i = -x_range; i < x_range; i+= x_precision)
    {
	    rect(i, func(i), f_pixel_size, f_pixel_size)
    }
}

function draw()
{   
    init_window()
   
    //WAVES
    //green()
    //f(x => sin(x) * 360)
    //blue()
    //f(x => cos(x) * 360)

    //QUADRATICS
    green()
    f(x => (Math.pow(x, 3) / 100) + (4 * Math.pow(x, 2) / 100) + 56 )
    
    //CENTRE CROSS
    white()
    centre_cross()
}
