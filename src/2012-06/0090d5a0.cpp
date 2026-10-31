// from server: 12% by Intel
struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    char pad[0x19];
    float minX;
    float maxX;
    float minY;
    float maxY;
    float minZ;
    float maxZ;
};

struct Tree
{
    Node *root;
    Node *nil;
    Node *findNode(const float *point, Node **outParent, Node **outLast) const;
};

Node *Tree::findNode(const float *point, Node **outParent, Node **outLast) const
{
    Node *current = nil->right;
    Node *parent = nil;
    Node *last = nil;

    if (current->pad[0x1d] == 0)
    {
        float px = point[0];
        while (true)
        {
            float nodeMinX = current->minX;
            if (nodeMinX > px || px > nodeMinX)
            {
                current = current->right;
            }
            else
            {
                float nodeMaxX = current->maxX;
                float py = point[1];
                if (py > nodeMaxX || nodeMaxX > py)
                {
                    current = current->right;
                }
                else
                {
                    float nodeMinY = current->minY;
                    float pz = point[2];
                    if (pz > nodeMinY || nodeMinY > pz)
                    {
                        current = current->right;
                    }
                    else
                    {
                        float nodeMaxY = current->maxY;
                        if (pz <= nodeMaxY)
                        {
                            current = current->left;
                            continue;
                        }
                        current = current->right;
                    }
                }
            }
            if (current->pad[0x1d] != 0)
                break;
        }
    }

    if (parent->pad[0x1d] != 0)
    {
        current = root->right;
    }
    else
    {
        current = parent->left;
    }

    if (current->pad[0x1d] == 0)
    {
        float px = point[0];
        do
        {
            float nodeMinX = current->minX;
            if (nodeMinX > px || px > nodeMinX)
            {
                parent = current;
                current = current->left;
            }
            else
            {
                float py = point[1];
                float nodeMaxX = current->maxX;
                if (py > nodeMaxX || nodeMaxX > py)
                {
                    parent = current;
                    current = current->left;
                }
                else
                {
                    float pz = point[2];
                    float nodeMaxY = current->maxY;
                    if (pz > nodeMaxY || nodeMaxY > pz)
                    {
                        current = current->left;
                        continue;
                    }
                    float nodeMinY = current->minY;
                    if (pz <= nodeMinY)
                    {
                        parent = current;
                        current = current->right;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
            }
        } while (current->pad[0x1d] == 0);
    }

    *outParent = last;
    *outLast = parent;
    return current;
}
