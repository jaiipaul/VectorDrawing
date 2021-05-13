# VectorDrawing
Draw a bitmap image from .vec file

# LAUNCHING APP

The VectorDrawing project can be launched by 3 methods at this time:
  > 1) ./VectorDrawing 'filename'
    This command will draw the image described in the .vec given in argument with a 1:1 scale.

  > 2) ./VectorDrawing 'filename' 'scale'
    This second command does the same as the previous one but let you choose the scale which the app will use to draw the image.

  > 3) ./VectorDrawing
    This last method launches a interactive terminal application.
    You'll start in home menu which ask if you want to create a new drawing (new .vec file), open an already existing one, or quit.
    Once you've opened a drawing, you'll be able to modify its properties (Size, Background and Scale), add and remove shapes, look at drawing information and draw it.
    When you choose to draw the image, a new .bmp file is created with the same name as the .vec file in the current directory.

# .vec SYNTAX

If you use this third method, you won't need to edit manually .vec file, but if you want to edit it yourself here is some elements of syntax:
  # SHAPES :
  > The app support 4 types of shapes : POINT, LINE, DISK, and RECTANGLE. Whenever you want to add one of these, you need add a new line starting with the type of shapes.
    Each shape has different geometrical parameters, here is how commands should be written :

      > POINT : X, Y, Z, RED, GREEN, BLUE, OPACITY;
      > LINE : X1, Y1, X2, Y2, Z, RED, GREEN, BLUE, OPACITY;
      > DISK : X, Y, RADIUS, Z, RED, GREEN, BLUE, OPACITY;
      > RECTANGLE : X, Y, WIDTH, HEIGHT, Z, RED, GREEN, BLUE, OPACITY;

  > RECTANGLE and DISK have alternate types :
      > RECTANGLE and DISK have only their contour drawn whereas RECTANGLE_F and DISK_F are full.

  #PROPERTIES :
  > In the .vec file you can also indicate some properties of the image : SIZE, BACKGROUND and SCALE.

      > SIZE : WIDTH, HEIGHT;
        - When the size command is enable, the image will always be drawn with the size you ask for. It acts as a window, shapes that are out of the borders are not drawn, but can be partially drawn if they are on the border.
        Example : You want to draw a sun in the top right corner. Size is set to 100x100, and you can place a DISK_F with its center in (100, 100) with the radius you want, and you'll a quarter of disk in the corner.

        - When the size command is not given or disabled, the image will be drawn with the dimensions determined with the biggest shapes in the drawing.

      > BACKGROUND : RED, GREEN, BLUE;

      > SCALE : S;
        - This command has the priority to set the scale of the drawing.
          It means when it is enable, and you launch ./VectorDrawing 'filename' ('scale') the image will be drawn with the scale given in th .vec file.

      These commands are added automatically when you create a .vec with the VectorDrawing application but are disabled and no parameters are given.

   > To disable a shape or a property command in the .vec file, use "//" at the beginning of the line, this comments the line and it won't be considered for loading and drawing.
   > To turn on/off any property in VectorDrawing terminal app, go in EDIT menu, then choose the property, you'll see a new menu, you can type ON or OFF to change its status.

   # VECTORDRAWING TERMINAL APP

   The app gives you the possibility to edit your drawing easily without writing a full .vec file.
   You can navigate into menus and enter parameter by typing what is asked to you.

   To navigate in menus, you can type in normal or capital letters, or use some shortcuts:
   #HOME menu:       |#MAIN menu:       |#SHAPES menu:     |
    > NEW  : +       |> DRAW   : D or d |> ADD    : +      | > BACK : <
    > OPEN : >       |> EDIT   : E or e |> REMOVE : -      |
    > QUIT : X or x  |> SHAPES : S or s |> LIST   : L or l |
                     |> INFO   : I or i |                  |
