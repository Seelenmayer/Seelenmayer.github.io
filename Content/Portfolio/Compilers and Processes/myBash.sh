#! /bin/bash

#Help
function h(){
  echo "   c                  = clear screen"
  echo "   l                  = display directory"
  echo "   s                  = source bash script"
  echo "   m x                = make directory x"
  echo "   c x                = change to directory x"
  echo "   get x y            = get course x assignment y"
  echo "   handin x y z       = handin course x assignment y message z"
  echo "   killassignment x y = kill git/local directory for course x assignment y"
}

#Clear Screen
function c(){
  clear
}

#Display Directory
function l(){
  ls
}

#Source myBash
function s(){
  cd
  source myBash.sh
  cd
  if [ $? -ne 0 ] ; then
    echo "   Failed to source myBash.sh."
  else
    echo "   Source Successful."
  fi
}

#Make Directory
function m(){
  set -v
  echo "   Making a new directory..."
  content=$@
  mkdir "$content"
  set +v
}

#Clone Assignment
function get(){
  set -v

  #Did the enter the correct number of commands?
  if [ $# -ne 2 ] ; then
    echo "   You did not enter 2 parameters. Please enter: \"get course assignment\"."
  else
    course=$1
    assignment=$2
    cd

    #Did the fork command run?
    ssh csci fork $course/$assignment $course/$USER/$assignment
    if [ $? -ne 0 ] ; then
      echo "   Failed to Fork."
    else
      echo "   Fork Complete."
      echo "   Cloning..."

      #Did the directory change to course?
      cd $course
      if [ $? -ne 0 ] ; then
        echo "   Failed to enter directory $course."
      else

        #Did the repository clone?
        git clone csci:$course/$USER/$assignment
        if [ $? -ne 0 ] ; then
          echo "   Failed to Clone."
        else
          echo "   Clone Complete."

          #Did the directory change to assignment?
          cd $assignment
          if [ $? -ne 0 ] ; then
            echo "   Failed to enter the directory $assignment."
          fi
        fi
      fi
    fi
  fi
  set +v
}

#Hand-In Assignment
function handin(){
  set -v

  #Did they enter the correct number of commands?
  if [ $# -ne 3 ] ; then
    echo "   You did not enter 3 parameters. Please enter: \"handin course assignment comment\"."
  else
    course=$1
    assignment=$2
    comment=$3
    cd

    #Did the directory change to course?
    cd $course
    if [ $? -ne 0 ] ; then
      echo "   Failed to enter the directory $course."
    else

      #Did the directory change to assignment?
      cd $assignment
      if [ $? -ne 0 ] ; then
        echo "   Failed to enter the directory $assignment."
      else

        #Did the assignment add?
        git add .
        if [ $? -ne 0 ] ; then
          echo "   Failed to add the $course directory."
        else

          #Did the assignment commit?
          git commit -m "$comment"
          if [ $? -ne 0 ] ; then
            echo "   Failed to commit."
          else

            #Did the assignment push?
            git push
            if [ $? -ne 0 ] ; then
              echo "   Failed to push."
            else
              echo "   Hand-in Successfull."
            fi
          fi
        fi
      fi
    fi
  fi
  set +v
}

#Delete Assignment
function killassignment(){
  set -v

  #Did they enter the correct number of commands?
  if [ $# -ne 2 ] ; then
    echo "   You did not enter 2 parameters. Please enter: \"killAssignment course assignment\"."
  else
    course=$1
    assignment=$2
    cd

    #Did the directory change to course?
    cd $course
    if [ $? -ne 0 ] ; then
      echo "   Failed to enter the directory $course."
    else

      #Did the directory change to assignment?
      cd $assignment
      if [ $? -ne 0 ] ; then
        echo "   Failed to enter the directory $assignment."
      else

        #Did the remote repository get removed?
        ssh csci D trash $course/$USER/$assignment
        if [ $? -ne 0 ] ; then
          echo "   Failed to remove the remote $assignment repository."
        fi

        #Did the local directory get removed?
        cd ..
        rm -rf $assignment
        if [ $? -ne 0 ] ; then
          echo "   Failed to remove the local $assignment directory."
        fi

        #Did the trash command display?
        ssh csci D list-trash 
        if [ $? -ne 0 ] ; then
          echo "   Failed to display the trash bin."
        fi
      fi
    fi
  fi
  set +v
}
