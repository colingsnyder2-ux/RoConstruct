// from server: 100% by atomic.potato
struct CRobloxWnd_RenderStatsItem {
    double m_0;
    double m_8;
    double m_10;
    double m_18;
    double m_20;
    double m_28;
    double m_30;
    double dot(const CRobloxWnd_RenderStatsItem* other);
};

double CRobloxWnd_RenderStatsItem::dot(const CRobloxWnd_RenderStatsItem* other)
{
    return other->m_30 * m_30
        + other->m_28 * m_28
        + other->m_20 * m_20
        + other->m_18 * m_18
        + other->m_10 * m_10
        + other->m_8 * m_8
        + m_0;
}
