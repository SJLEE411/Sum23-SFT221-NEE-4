#ifndef FINDER_H
#define FINDER_H

struct Truck {
    int truck_id;
    float weight_capacity;
    float volume_capacity;
    int allocated_shipments;
    int* destination_counts;
};

struct Building {
    int building_id;
    float x;
    float y;
    int is_obstacle;
    int* adjacency_matrix;
};

struct PathRequest {
    int start_building_id;
    int destination_building_id;
};


#endif  // FINDER_H
