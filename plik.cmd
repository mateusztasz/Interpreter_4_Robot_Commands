#define PROMIEN 50
#define PREDKOSC 30
#define PREDKOSC_BEZ_OBIEKTU 200
#define PROMIEN_2 100
#define ODLEGLOSC 78.5398
#define ODLEGLOSC_2 157.0796

Turn PREDKOSC_BEZ_OBIEKTU ODLEGLOSC PROMIEN
Grasper 1

Turn PREDKOSC ODLEGLOSC -PROMIEN
Move PREDKOSC PROMIEN
Turn PREDKOSC ODLEGLOSC -PROMIEN
Grasper 0

Turn PREDKOSC_BEZ_OBIEKTU ODLEGLOSC_2 -PROMIEN
Grasper 1

Turn PREDKOSC ODLEGLOSC PROMIEN
Move PREDKOSC PROMIEN
Turn -PREDKOSC ODLEGLOSC PROMIEN
Grasper 0

Turn PREDKOSC_BEZ_OBIEKTU ODLEGLOSC_2 -PROMIEN
Grasper 1

Turn PREDKOSC ODLEGLOSC -PROMIEN
Move -PREDKOSC PROMIEN
Turn PREDKOSC ODLEGLOSC -PROMIEN
Grasper 0

Turn PREDKOSC_BEZ_OBIEKTU ODLEGLOSC_2 -PROMIEN
Grasper 1

Turn PREDKOSC ODLEGLOSC -PROMIEN
Move -PREDKOSC PROMIEN
Turn PREDKOSC ODLEGLOSC -PROMIEN
Grasper 0



Turn PREDKOSC_BEZ_OBIEKTU ODLEGLOSC PROMIEN
Move PREDKOSC_BEZ_OBIEKTU PROMIEN_2

Rotate 45 90
Move PREDKOSC_BEZ_OBIEKTU 100
Rotate 45 90

