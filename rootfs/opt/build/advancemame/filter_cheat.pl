#!/usr/bin/perl


open(ROM, "ls --format=single-column /mame/rom/*.zip|");
while(!eof(ROM)){
  $ROM = <ROM>;
  chop $ROM;
  ($lixo, $rom) = split(/\/rom\//,$ROM);
  ($rom, $lixo) = split(/\.zip/,$rom);
  push @ROMS, $rom;
}
close ROM;

open(F, "cheat.dat");
while(!eof(F)){
  $l = <F>;
  foreach $rom(@ROMS){
    if($l =~ /^\:$rom\:/){
      print $l;
    }
  }
}
