import turtle
import sys
import random
import math
 
def gen(n, result='[X]'):
    for _ in range(n):
        result = result.replace('F', 'FF')
        result = result.replace('X', 'F-[[X]+X]+F[+FX]-X')
 
    return result
 
def draw(cmds, size=2):
    stack = []
    for cmd in cmds:
        if cmd=='F':
            turtle.forward(size)
        elif cmd=='-':
            t = random.randrange(0,7,1)
            p = ["Red","Green","Blue","Grey","Yellow","Pink","Brown"]
            turtle.color(p[t])
            turtle.left(15) 
        elif cmd=='+':
            turtle.right(15)
            t = random.randrange(0,7,1)
            p = ["Red","Green","Blue","Grey","Yellow","Pink","Brown"]
            turtle.color(p[t]) 
        elif cmd=='X':
            pass
        elif cmd=='[':
            stack.append((turtle.position(), turtle.heading()))
        elif cmd==']':
            position, heading = stack.pop()
            turtle.penup()
            turtle.setposition(position)
            turtle.setheading(heading)
            turtle.pendown()
    turtle.update()
 
def set():
    turtle.hideturtle()
    turtle.tracer(1e3,1)
    turtle.left(95)
    turtle.penup()
    turtle.goto(0,-turtle.window_height()/2)
    turtle.pendown()
    
set()

pl = gen(6)
for i in range(1,9):
    turtle.goto(300-70*i,-300) 
    k=-random.randrange(0,18,1)  
    turtle.left(k)  
    draw(pl, 2+k/20)
    turtle.left(-k)

turtle.penup()
turtle.goto(300,300)
turtle.pendown()
    
turtle.color('red', 'yellow')
turtle.begin_fill()
while True:
    turtle.goto(300,300)
    turtle.forward(200)
    turtle.left(170)
    if abs( turtle.pos()) < 1:
        break

turtle.penup()
