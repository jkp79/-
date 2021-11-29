function ?-Greedy
for (a,c) ? A ¡¤ C do
wins(a,c )
, trials(a,c ) ¡û knowledge-base(a,c)
P (a|C(w)) ¡û
wins(a,C(w )
trials(a,C(w )
end for
while stop criteria not met do
S = (w, P (a|w)) ? w in the current screen
if random() > ? then
e ¡û random w ¡Ê S
else
e ¡û max (P (a|w)), (w, P (a|w)) ¡Ê S
end if
r ¡û e.w.perform(e.a)
wins(a,C(w)) ¡û wins +r
trials(a,C(w)) ¡û trials +1
P (a|C(w)) ¡û
wins(a,C(w )
trials(a,C(w )
end while
end function



function thompson-sampling
for (a,c) ? A ¡¤ C do
wins(a,c )
, trials(a,c ) ¡û knowledge-base(a,c)
P (a|C(w)) ¡û B(1+wins(a,c ), 1+trials(a,c )?wins(a,c ))
end for
while stop criteria not met do
S ¡û BC(a|w)? w in the current screen
L ¡û sample(s) | ? s ? S
e ¡û max (L)
r ¡û e.w.perform(e.a)
wins(a,C(w)) ¡û wins +r
trials(a,C(w)) ¡û trials +1
P (a|C(w)) ¡û B(1+winsC(w), 1+trialsC(w)?winsC(w))
end while
end function



function knowledge-base(action, class)
p ¡û probability(action,class)
wins ¡û p ¡Á¦×
trials ¡û ¦×
return wins, trials
end function


function
fitness-proportionate-selection-with-reinforcement
learning
for (a,c) ? A ¡¤ C do
p ¡û crowd-based-model(action,class)
wins ¡û p ¡Á¦×
trials ¡û ¦×
P (a|C(w)) ¡û
wins(a,C(w )
trials(a,C(w )
end for
while stop criteria not met do
S = (w, P (a|w)) ? w in the current screen
e ¡û originalStochasticSelectAlgorithm(S, P)
r ¡û e.w.perform(e.a)
wins(a,C(w)) ¡û wins +r
trials(a,C(w)) ¡û trials +1
P (a|C(w)) ¡û
wins(a,C(w )
trials(a,C(w )
end while
end function

