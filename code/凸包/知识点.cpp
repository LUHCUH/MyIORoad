1. ǰ��֪ʶ��
    (1) pi = acos(-1);
    (2) ���Ҷ��� c^2 = a^2 + b^2 - 2abcos(t)

2. �������ıȽ�
const double eps = 1e-8;
int sign(double x)  // ���ź���
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}
int cmp(double x, double y)  // �ȽϺ���
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

3. ����
    3.1 �����ļӼ�������������
    3.2 �ڻ�������� A��B = |A||B|cos(C)
        (1) �������壺����A������B�ϵ�ͶӰ��B�ĳ��ȵĳ˻���
        (2) ����ʵ��
        double dot(Point a, Point b)
        {
            return a.x * b.x + a.y * b.y;
        }
    3.3 ���������� AxB = |A||B|sin(C)
        (1) �������壺����A��B�ųɵ�ƽ���ı��ε����������B��A����ʱ�뷽��Ϊ����
        (2) ����ʵ��
        double cross(Point a, Point b)
        {
            return a.x * b.y - b.x * a.y;
        }
    3.4 ���ú���
        3.4.1 ȡģ
        double get_length(Point a)
        {
            return sqrt(dot(a, a));
        }
        3.4.2 ���������н�
        double get_angle(Point a, Point b)
        {
            return acos(dot(a, b) / get_length(a) / get_length(b));
        }
        3.4.3 ���������������ɵ�ƽ���ı����������
        double area(Point a, Point b, Point c)
        {
            return cross(b - a, c - a);
        }
        3.4.5 ����A˳ʱ����תC�ĽǶȣ�
        Point rotate(Point a, double angle)
        {
            return Point(a.x * cos(angle) + a.y * sin(angle), -a.x * sin(angle) + a.y * cos(angle));
        }
4. ������
    4.1 ֱ�߶���
        (1) һ��ʽ ax + by + c = 0
        (2) ����ʽ p0 + vt
        (3) б��ʽ y = kx + b
    4.2 ���ò���
        (1) �жϵ���ֱ���� A x B = 0
        (2) ��ֱ���ཻ
        // cross(v, w) == 0����ֱ��ƽ�л����غ�
        Point get_line_intersection(Point p, Vector v, Point q, vector w)
        {
            vector u = p - q;
            double t = cross(w, u) / cross(v, w);
            return p + v * t;
        }
        (3) �㵽ֱ�ߵľ���
        double distance_to_line(Point p, Point a, Point b)
        {
            vector v1 = b - a, v2 = p - a;
            return fabs(cross(v1, v2) / get_length(v1));
        }
        (4) �㵽�߶εľ���
        double distance_to_segment(Point p, Point a, Point b)
        {
            if (a == b) return get_length(p - a);
            Vector v1 = b - a, v2 = p - a, v3 = p - b;
            if (sign(dot(v1, v2)) < 0) return get_length(v2);
            if (sign(dot(v1, v3)) > 0) return get_length(v3);
            return distance_to_line(p, a, b);
        }
        (5) ����ֱ���ϵ�ͶӰ
        double get_line_projection(Point p, Point a, Point b)
        {
            Vector v = b - a;
            return a + v * (dot(v, p - a) / dot(v, v));
        }
        (6) ���Ƿ����߶���
        bool on_segment(Point p, Point a, Point b)
        {
            return sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0;
        }
        (7) �ж����߶��Ƿ��ཻ
        bool segment_intersection(Point a1, Point a2, Point b1, Point b2)
        {
            double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
            double c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
            return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
        }
5. �����
    5.1 ������
    5.1.1 ���
        (1) ���
        (2) ���׹�ʽ
            p = (a + b + c) / 2;
            S = sqrt(p(p - a) * (p - b) * (p - c));
    5.1.2 ����������
        (1) ���ģ����ԲԲ��
            �����д��߽��㡣����������������ľ������
        (2) ���ģ�����ԲԲ��
            ��ƽ���߽��㣬�����߾������
        (3) ����
            �������߽���
        (4) ����
            �������߽��㣨������������������ƽ������С�ĵ㣬�������ڵ����߾���֮�����ĵ㣩
    5.2 ��ͨ�����
        ͨ������ʱ��洢���е�
        5.2.1 ����
        (1) �����
            ����ͬһƽ���Ҳ���ͬһֱ���ϵĶ����߶���β˳�������Ҳ��ཻ����ɵ�ͼ�νж����
        (2) �򵥶����
            �򵥶�����ǳ����ڱ��������߲��ཻ�Ķ����
        (3) ͹�����
            ������ε�����һ����һ��ֱ�ߣ���������������㶼������ֱ�ߵ�ͬ�࣬����������ν���͹�����
            ����͹�������Ǻ;�Ϊ360��
            ����͹������ڽǺ�Ϊ(n?2)180��
        5.2.2 ���ú���
        (1) �������������һ����͹����Σ�
        ���ǿ��Դӵ�һ�����������͹����ηֳ�n ? 2�������Σ�Ȼ��������������
        double polygon_area(Point p[], int n)
        {
            double s = 0;
            for (int i = 1; i + 1 < n; i ++ )
                s += cross(p[i] - p[0], p[i + 1] - p[i]);
            return s / 2;
        }
        (2) �жϵ��Ƿ��ڶ�����ڣ���һ����͹����Σ�
        a. ���߷����Ӹõ�������һ�������б߶���ƽ�е����ߡ��������Ϊż�������ڶ�����⣬Ϊ���������ڶ�����ڡ�
        b. ת�Ƿ�
        (3) �жϵ��Ƿ���͹�������
        ֻ���жϵ��Ƿ������бߵ���ߣ���ʱ��洢����Σ���
    5.3 Ƥ�˶���
        Ƥ�˶�����ָһ����������ж����ڸ���ϵĶ���������ʽ�ù�ʽ���Ա�ʾΪ:
            S = a + b/2 - 1
        ����a��ʾ������ڲ��ĵ�����b��ʾ����α߽��ϵĵ�����S��ʾ����ε������
6. Բ
    (1) Բ��ֱ�߽���
    (2) ��Բ����
    (3) �㵽Բ������
    (4) ��Բ������
    (5) ��Բ�ཻ���

���ߣ�yxc
���ӣ�https://www.acwing.com/activity/content/code/content/635453/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
