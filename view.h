/**
* view.h
*/

// Header Guards:
#ifndef VIEW_H
#define VIEW_H

class View {
public:
    // Initialize the view:
    bool init();

    // Load Bit Rep:
    load(BitRep &br);
    refresh();
};


#endif