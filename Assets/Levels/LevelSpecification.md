## Level specification
1) First you have to define map properties:
    ```
    # Map properties
    16 # Map width
    15 # Map height
    ```
2) Next you have to describe how to draw your map:
   ```
   E - empty
   = - wall
   . - floor
   X - target
   R - rock
   P - player
   N - next line
   
   To draw map element you have to specify how many elements you want to draw and it's id:
  
   6E - draw 6 empty space
   4= - draw 4 walls
   6E - draw 6 empty space
   1P - draw player
   N - go to next line
   ```
   Example map:
   ```
    6E4=6EN
    6E1=2X1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2.1=6EN
    6E1=2R1=6EN
    6E1=1.1P1=6EN
    6E4=6EN
   ```
   
   It will draw like this:
   ```
   EEEEEE====EEEEEE
   EEEEEE=XX=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=..=EEEEEE
   EEEEEE=RR=EEEEEE
   EEEEEE=.P=EEEEEE
   EEEEEE====EEEEEE
   ```