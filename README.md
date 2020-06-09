# Drawing application project in C++ using wxWidgets

## Goals
1. Drawing
   - line
   - circle

2. Handle attributs
   - background color (fill)
   - border color (stroke)
   - stroke-width
   - depth (move foreground, background)

3. Handle functions
   - edit
   - delete
   - copy / paste
   - lock
   - undo / redo
   - open / save (SVG or something more simple)

## Strategy

We will use MVC and Observer pattern.  
We will be inspired by web API using for HTML to make our structures.  

## Structures

### Visual part

**Node**: Encapsulation of the depth concept.  
**Element** (inherit from Element): Represent common attributes of drawing object (id, fill, stroke, strokeWidth, locked).  
**Line** (inherit from Element): Represent line (Origine : x1, y1; Destination: x2, y2).  
**Circle** (inherit from Element): Represent circle (cx cy r).  

### Functional part

**UserAction**: Represent the an element update made by the user.  
**UndoRedo** (contain list of UserAction): Represent all user action in a timeline.  

**Clipboard**: To handle copy/paste function.  

**Parser**: To convert our drawing structure to SVG format and the reverse.  
**OpenSave**: Encapsulation of the read/write to a SVG file.  
