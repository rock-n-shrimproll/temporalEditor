insert into flex(meaning,flex_masc_1,flex_masc_2,flex_masc_3,flex_masc_4,flex_masc_5,flex_masc_6,
    flex_neu_1,flex_neu_2,flex_neu_3,flex_neu_4,flex_neu_5,flex_neu_6,
    flex_fem_1,flex_fem_2,flex_fem_3,flex_fem_4,flex_fem_5,flex_fem_6,
    flex_plur_1,flex_plur_2,flex_plur_3,flex_plur_4,flex_plur_5,flex_plur_6)
values ('склонение 1а','ый', 'ого', 'ому', 'ый', 'ым', 'ом',
'ая', 'ой', 'ой', 'ую', 'ой', 'ой',
'ое', 'ого', 'ому', 'ое', 'ым', 'ом', 
'ые', 'ых', 'ым', 'ые', 'ыми', 'ых');

insert into flex(meaning,flex_masc_1,flex_masc_2,flex_masc_3,flex_masc_4,flex_masc_5,flex_masc_6,
    flex_neu_1,flex_neu_2,flex_neu_3,flex_neu_4,flex_neu_5,flex_neu_6,
    flex_fem_1,flex_fem_2,flex_fem_3,flex_fem_4,flex_fem_5,flex_fem_6,
    flex_plur_1,flex_plur_2,flex_plur_3,flex_plur_4,flex_plur_5,flex_plur_6)
values ('склонение 1b','ой', 'ого', 'ому', 'ой', 'ым', 'ом',
'ая', 'ой', 'ой', 'ую', 'ой', 'ой',
'ое', 'ого', 'ому', 'ое', 'ым', 'ом', 
'ые', 'ых', 'ым', 'ые', 'ыми', 'ых');

insert into flex(meaning,flex_masc_1,flex_masc_2,flex_masc_3,flex_masc_4,flex_masc_5,flex_masc_6,
    flex_neu_1,flex_neu_2,flex_neu_3,flex_neu_4,flex_neu_5,flex_neu_6,
    flex_fem_1,flex_fem_2,flex_fem_3,flex_fem_4,flex_fem_5,flex_fem_6,
    flex_plur_1,flex_plur_2,flex_plur_3,flex_plur_4,flex_plur_5,flex_plur_6)
values ('склонение 2а', 'ий', 'его', 'ему', 'ий', 'им', 'ем',
'яя', 'ей', 'ей', 'юю', 'ей', 'ей',
'ее', 'его', 'ему', 'ее', 'им', 'ем', 
'ие', 'их', 'им', 'ие', 'ими', 'их');

insert into flex(meaning,flex_masc_1,flex_masc_2,flex_masc_3,flex_masc_4,flex_masc_5,flex_masc_6,
    flex_neu_1,flex_neu_2,flex_neu_3,flex_neu_4,flex_neu_5,flex_neu_6,
    flex_fem_1,flex_fem_2,flex_fem_3,flex_fem_4,flex_fem_5,flex_fem_6,
    flex_plur_1,flex_plur_2,flex_plur_3,flex_plur_4,flex_plur_5,flex_plur_6)
values ('склонение 3а', 'ий', 'ого', 'ому', 'ий', 'им', 'ом',
'яя', 'ой', 'ой', 'ую', 'ой', 'ой',
'ое', 'ого', 'ому', 'ое', 'им', 'ом', 
'ие', 'их', 'им', 'ие', 'ими', 'их');

insert into flex(meaning,flex_masc_1,flex_masc_2,flex_masc_3,flex_masc_4,flex_masc_5,flex_masc_6,
    flex_neu_1,flex_neu_2,flex_neu_3,flex_neu_4,flex_neu_5,flex_neu_6,
    flex_fem_1,flex_fem_2,flex_fem_3,flex_fem_4,flex_fem_5,flex_fem_6,
    flex_plur_1,flex_plur_2,flex_plur_3,flex_plur_4,flex_plur_5,flex_plur_6)
values ('склонение 4а', 'ий', 'его', 'ему', 'ий', 'им', 'ем',
'ая', 'ей', 'ей', 'ую', 'ей', 'ей',
'ее', 'его', 'ему', 'ее', 'им', 'ем', 
'ие', 'их', 'им', 'ие', 'ими', 'их');

insert into temporality(temp_class, temp_type, temp_subtype)
values ('периодическое', '', '');
insert into temporality(temp_class, temp_type, temp_subtype)
values ('интервальное', 'открытое', 'начало');
insert into temporality(temp_class, temp_type, temp_subtype)
values ('интервальное', 'открытое', 'конец');
insert into temporality(temp_class, temp_type, temp_subtype)
values ('интервальное', 'открытое', 'длительность');
insert into temporality(temp_class, temp_type, temp_subtype)
values ('точечное', '', '');

insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., м.р., ед.ч.', 'а', 'и', 'е', 'у', 'ей', 'е');
insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., м.р., ед.ч.', 'а', 'ы', 'е', 'у', 'ой', 'е');
insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., ж.р., ед.ч.', 'я', 'и', 'е', 'ю', 'ей', 'е');
Insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., ж.р., ед.ч.', 'я', 'и', 'и', 'ю', 'ей', 'и');
Insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., м.р., мн.ч','и', 'ей', 'ам', 'ей', 'ами', 'ах');
Insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., м.р., мн.ч','ы', '', 'ам', '', 'ами', 'ах');
Insert into noun_flex(meaning, noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
values ('1-ое скл., м.р., мн.ч','и', 'ей', 'ям', 'ей', 'ями', 'ях');


