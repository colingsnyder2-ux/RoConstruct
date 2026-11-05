// from server: 34% by atomic.potato
struct DxUserInputJob
{
    float x;
    float y;
    void DivideInto(DxUserInputJob* result, const DxUserInputJob* divisor);
};

void DxUserInputJob::DivideInto(DxUserInputJob* result, const DxUserInputJob* divisor)
{
    result->x = x / divisor->x;
    result->y = y / divisor->y;
}
