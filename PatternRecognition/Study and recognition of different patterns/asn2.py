from opencv import cv
from opencv import highgui
def main():



    a_window = highgui.cvNamedWindow('a_window',highgui.CV_WINDOW_AUTOSIZE)
    '''
    image=cv.LoadImage('desktopBlue.jpg', cv.CV_LOAD_IMAGE_COLOR)
    dst = cv.cvCreateImage((600,200), 8, 3)
    cv.cvLine(dst,(100,200),(100,100),(0,0,1))
    cv.cvCircle(dst,(-10,-10),10,(0,0,0))
    highgui.cvShowImage('a_window',dst)
    highgui.cvWaitKey(10000)

    '''

    dst = cv.cvCreateImage((700,700), 8, 3)
    cv.cvLine(dst,(20,20),(20,680),(0xFF,0xFF,0xFF),2,0)
    cv.cvLine(dst,(20,680),(680,680),(0xFF,0xFF,0xFF),2,0)




    no = int(raw_input("Enter total no. of points"))
    a=[]
    for i in range(no):
        no1=int(raw_input("Enter x coord: "))
        no2=int(raw_input("Enter y coord: "))
        a.append([no1,no2,0])
    print a
    slope=[]
    for i in range(no):
        a[i][2]=1
        j=0
        slope=[[find_slope(a[i][0],a[i][1],a[j][0],a[j][1]), j]]
        j=j+1
        while(j<no):
            slope.append([find_slope(a[i][0],a[i][1],a[j][0],a[j][1]), j])
            j=j+1


        slope.sort()
        j=1
        temp_arr = []
        temp_arr.append(slope[0])
        while(j<no):
#            print "temparr:"+str(temp_arr)
            if(i==slope[j][1]):
                j=j+1
                continue
            if(slope[j][0]==temp_arr[0][0]):
                if(a[slope[j][1]][2]==0):
                    temp_arr.append(slope[j])

            else:
                if(len(temp_arr)>=2):
                    print "Following points are in a line:"
                    for k in range(len(temp_arr)):
                        print "["+str(a[temp_arr[k][1]][0])+","+str(a[temp_arr[k][1]][1])+"]"
                        a[temp_arr[k][1]][2]=1;
                    print "["+str(a[i][0])+","+str(a[i][1])+"]"
                    for k in range(len(temp_arr)-1):
                        cv.cvLine(dst,(20+a[temp_arr[k][1]][0]*10,680-a[temp_arr[k][1]][1]*10),(20+a[temp_arr[k+1][1]][0]*10,680-a[temp_arr[k+1][1]][1]*10),(0,0,0xFF),2,0)
                    cv.cvLine(dst,(20+a[i][0]*10,680-a[i][1]*10),(20+a[temp_arr[k+1][1]][0]*10,680-a[temp_arr[k+1][1]][1]*10),(0,0,0xFF),2,0)

                temp_arr = []
                temp_arr.append(slope[j])
            j=j+1

        if(len(temp_arr)>=2):
            print "Following points are in a line:"
            for k in range(len(temp_arr)):
                print "["+str(a[temp_arr[k][1]][0])+","+str(a[temp_arr[k][1]][1])+"]"
                a[temp_arr[k][1]][2]=1;
            print "["+str(a[i][0])+","+str(a[i][1])+"]"
            for k in range(len(temp_arr)-1):
                cv.cvLine(dst,(20+a[temp_arr[k][1]][0]*10,680-a[temp_arr[k][1]][1]*10),(20+a[temp_arr[k+1][1]][0]*10,680-a[temp_arr[k+1][1]][1]*10),(0,0,0xFF),2,0)
                cv.cvLine(dst,(20+a[i][0]*10,680-a[i][1]*10),(20+a[temp_arr[k+1][1]][0]*10,680-a[temp_arr[k+1][1]][1]*10),(0,0,0xFF),2,0)

        slope=[]
    for k in range(no):
        cv.cvLine(dst,(20+a[k][0]*10,680-a[k][1]*10),(20+a[k][0]*10,680-a[k][1]*10),(0xFF,0,0),4,0)

    highgui.cvShowImage('a_window',dst)
    highgui.cvWaitKey(90000)



def find_slope(x1,y1,x2,y2):
    if(x1==x2):
        return 9999.0
    a=1.0
    x1=x1*1.0
    x2=x2*1.0
    y1=y1*1.0
    y2=y2*1.0
    a=float((y2-y1)/(x2-x1))
    return a




if __name__=="__main__":
    main()
