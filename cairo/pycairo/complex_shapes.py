#!/usr/bin/python

import math

'''
ZetCode PyCairo tutorial 

This code example draws another
three shapes in PyCairo.

Author: Jan Bodnar
Website: zetcode.com 
Last edited: April 2016
'''

from gi.repository import Gtk
import cairo


class cv(object):
    
    points = ( 
        ( 0, 85 ), 
        ( 75, 75 ), 
        ( 100, 10 ), 
        ( 125, 75 ), 
        ( 200, 85 ),
        ( 150, 125 ), 
        ( 160, 190 ),
        ( 100, 150 ), 
        ( 40, 190 ),
        ( 50, 125 ),
        ( 0, 85 )
    )


class Example(Gtk.Window):

    def __init__(self):
        super(Example, self).__init__()
        
        self.init_ui()
        
        
    def init_ui(self):    

        darea = Gtk.DrawingArea()
        darea.connect("draw", self.on_draw)
        self.add(darea)

        self.set_title("Complex shapes")
        self.resize(460, 240)
        self.set_position(Gtk.WindowPosition.CENTER)
        self.connect("delete-event", Gtk.main_quit)
        self.show_all()
        
    
    def on_draw(self, wid, cr):

        cr.set_source_rgb(0.6, 0.6, 0.6)
        cr.set_line_width(1)

        for i in range(10):
            cr.line_to(cv.points[i][0], cv.points[i][1])

        cr.fill()

        cr.move_to(240, 40)
        cr.line_to(240, 160)
        cr.line_to(350, 160)
        cr.fill()

        lg3 = cairo.LinearGradient(50, 0,  100, 0)
        lg3.add_color_stop_rgba(0.1, 1, 0, 0, 1) 
        lg3.add_color_stop_rgba(0.5, 1, 1, 1, 1) 
        lg3.add_color_stop_rgba(0.9, 0, 0, 1, 1) 


        cr.move_to(380, 40)
        cr.line_to(380, 160)
        cr.line_to(450, 160)
        cr.curve_to(440, 155, 380, 145, 380, 40)
        cr.set_source(lg3)
        cr.fill()

        r1 = cairo.RadialGradient(0, 0, 50, 0, 0, 100);


        r1.add_color_stop_rgba(0, 1, 0, 0, 1)
        r1.add_color_stop_rgba(0.2, 1, 0, 0, 1)
        r1.add_color_stop_rgba(1, 1, 0, 0, 0.2)
        '''
        cr.move_to(50, 0)
        '''
        cr.arc(0, 0, 50, 0, math.pi/2)
        '''
        cr.line_to(0,100)
        '''
        cr.arc_negative(0, 0, 100,  math.pi/2, 0)
        '''
        cr.line_to(50,0)
        '''
        cr.close_path()
        cr.set_source(r1)
        cr.fill()


        '''
        cr.move_to(100, 100)
        cr.line_to(130, 50)
        cr.line_to(150, 100)
        cr.arc(100, 100, 50, 0, math.pi/4)
        cr.close_path()
        cr.fill()
        '''



    
def main():
    
    app = Example()
    Gtk.main()
        
        
if __name__ == "__main__":    
    main()
