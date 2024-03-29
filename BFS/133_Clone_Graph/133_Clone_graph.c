/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct Node* cloneHelpler(struct Node *s, bool* hash, struct Node ** data){
    if(hash[s->val]){
        return data[s->val];
    }
    struct Node * root = malloc(sizeof(struct Node));

    hash[s->val] = true;
    data[s->val] = root; 

    root->val = s->val;
    root->numNeighbors = s->numNeighbors;
    root->neighbors = malloc(s->numNeighbors * sizeof(struct Node *));
    for(int i = 0; i < s->numNeighbors; i++){
        root->neighbors[i] = cloneHelpler(s->neighbors[i], hash, data); 
    }
    return root;
}

struct Node *cloneGraph(struct Node *s) {
    if(s == NULL){
        return NULL;
    }
    //hash
    bool* hash = calloc(101, sizeof(bool));
    struct Node ** data = malloc(sizeof(struct Node *) * 101); 
    return cloneHelpler(s, hash, data);
}