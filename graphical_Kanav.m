format short
clc
clear
A=[4 1; 3 4];
b=[5;6];
c=[2;3];
x1=0:0.001:max(b);
x21 = (b(1)-A(1,1)*x1)/A(1,2);
x22 = (b(2)-A(2,1)*x1)/A(2,2);
x21(find(x21<0))=nan;
x22(find(x22<0))=nan;
plot(x1,x21,'r',x1,x22,'g')
xlabel('value of x1')
ylabel('value of x2')
grid on;
title('plotting');
c1 = find(x1==0);
c2= find(x21==0);
cons1 =[x1([c1 c2]); x21([c1 c2])]';
c3= find(x22==0);
cons2 =[x1([c1 c3]); x22( [c1 c3])]';
corner = unique([cons1; cons2], 'rows')
 int=[0 0];
for i= 1:size(A,1)
    for j=i+1:size(A,1)
        a=[A(i,:); A(j,:)];
        B=[b(i); b(j)];
        x=a\B;
        if x>=0
           pt= x'
        else
            pt=[];
        end
           int=[int; pt]
    end
end
all_pts=[int; corner];
u_pt= unique(all_pts, 'rows')
 for i = 1 : size(A,1)
    constraint = A(i,1)* u_pt(:,1) + A(i,2) * u_pt(:,2) - b(i);
    NF = find(constraint > 0);
    u_pt(NF,:) = [];
 end
 FP=unique(u_pt,'rows')
%  if size(FP,1)==0
%      disp('no solution')
%  else
     
 for i=1:size(FP,1)
z(i,:)= FP(i,:)*c;
 end
[opt_val, index] = max(z)
opt_pt=u_pt(index,:)