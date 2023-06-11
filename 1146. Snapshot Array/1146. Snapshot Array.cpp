class SnapshotArray {
    vector<map<int, int>> snaps;
    int id = 0;
public:
    SnapshotArray(int length) {
        snaps.resize(length);

        for(int i = 0; i < length; i++)
            snaps[i][id] = 0;
    }
    
    void set(int index, int val) {
        snaps[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        if(snaps[index].count(snap_id) == 0) {
            auto it = --snaps[index].lower_bound(snap_id);
            return it->second;
        }

        return snaps[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
