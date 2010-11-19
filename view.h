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

    // Play an individual column from a bit_rep:
    void play_col(vector<bool> to_play);
};

#endif