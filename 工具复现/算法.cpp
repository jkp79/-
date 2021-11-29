function ?-Greedy
for (a,c) ? A �� C do
wins(a,c )
, trials(a,c ) �� knowledge-base(a,c)
P (a|C(w)) ��
wins(a,C(w )
trials(a,C(w )
end for
while stop criteria not met do
S = (w, P (a|w)) ? w in the current screen
if random() > ? then
e �� random w �� S
else
e �� max (P (a|w)), (w, P (a|w)) �� S
end if
r �� e.w.perform(e.a)
wins(a,C(w)) �� wins +r
trials(a,C(w)) �� trials +1
P (a|C(w)) ��
wins(a,C(w )
trials(a,C(w )
end while
end function



function thompson-sampling
for (a,c) ? A �� C do
wins(a,c )
, trials(a,c ) �� knowledge-base(a,c)
P (a|C(w)) �� B(1+wins(a,c ), 1+trials(a,c )?wins(a,c ))
end for
while stop criteria not met do
S �� BC(a|w)? w in the current screen
L �� sample(s) | ? s ? S
e �� max (L)
r �� e.w.perform(e.a)
wins(a,C(w)) �� wins +r
trials(a,C(w)) �� trials +1
P (a|C(w)) �� B(1+winsC(w), 1+trialsC(w)?winsC(w))
end while
end function



function knowledge-base(action, class)
p �� probability(action,class)
wins �� p ����
trials �� ��
return wins, trials
end function


function
fitness-proportionate-selection-with-reinforcement
learning
for (a,c) ? A �� C do
p �� crowd-based-model(action,class)
wins �� p ����
trials �� ��
P (a|C(w)) ��
wins(a,C(w )
trials(a,C(w )
end for
while stop criteria not met do
S = (w, P (a|w)) ? w in the current screen
e �� originalStochasticSelectAlgorithm(S, P)
r �� e.w.perform(e.a)
wins(a,C(w)) �� wins +r
trials(a,C(w)) �� trials +1
P (a|C(w)) ��
wins(a,C(w )
trials(a,C(w )
end while
end function

